class GPU_Sparse: private GPU_methods {
    public:
        // Based on cuSPARSE CSR three array zero based indexing.
        // https://docs.nvidia.com/cuda/cusparse/index.html#compressed-sparse-row-format-csr

        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;          // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;          // Device vector of length Size[2] storing type int.
        cusparseMatDescr_t descr = NULL;       // Matrix description.
        
        // Methods
        // Links to GPU_methods.dadd().
        GPU_Sparse add ( const double a ) {
            
            // Initialize result Vector.
            GPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call GPU_methods.dadd().
            y.Values = dadd(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spdadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        GPU_Sparse trans (  ) {
            
            GPU_Sparse result(Size[1],Size[0],Size[2]);

            spdtrans(Values,I,J,result.Values,result.I,result.J);

            return result;

        }

        // Links to GPU_methods.dscp().
        GPU_Sparse scp ( const double a ) {
            
            // Initialize result Vector.
            GPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call GPU_methods.dscp().
            y.Values = dscp(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }
        
        // Links to GPU_methods.spdgemv().
        GPU_Dense mv ( const GPU_Dense& x ) {

            // Initialize result Vector.
            GPU_Dense y(Size[0],1);

            // Check if the dimensions are correct.
            assert((Size[1] == x.Size[0]) && (x.isVector == 1));

            // Create pointers.
            const double * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ip = thrust::raw_pointer_cast(&I[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call GPU_methods.spdgemv().
            y.Values = spdgemv(Size[0],Size[1],Size[2],Vp,Ip,Jp,xp,descr);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Print the matrix.
        void print (  ) {

            // Transport to host memory.
            thrust::host_vector<double> V_temp = Values;
            thrust::host_vector<int> J_temp = J;
            thrust::host_vector<int> I_temp = I;

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Print first line.
            std::cout << "\n\tValues\t\t" << "(i,j)" << std::endl; 

            // Print.
            int l = 0;
            for (int k = 0; k < Size[2]; k++) {
                if (k == I_temp[l+1]) { l++; }
                std::cout << "\n\t" << V_temp[k] << "\t(" << l << "," << J_temp[k] << ")";
            } std::cout << "\n\n";

        }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {

            // Create temporary transposed matrix.
            GPU_Sparse temp = trans();

            // Copy to host memory.
            thrust::host_vector<double> V_temp = temp.Values;
            thrust::host_vector<int> i_temp = temp.I;
            thrust::host_vector<int> j_temp = temp.J;

            // Create pointer.
            double * V = thrust::raw_pointer_cast(&V_temp[0]);
            int * i = thrust::raw_pointer_cast(&i_temp[0]);
            int * j = thrust::raw_pointer_cast(&j_temp[0]);

            // Create MatIO Sparse stream. 
            matsparse_save sparse_temp(V,j,i,Size[2],Size[1]);

            // Write to MAT file.
            mat_file.save(varname,"sparse",sparse_temp.sparsestream,Size[0],Size[1]);

        }

        // Constructor
        GPU_Sparse ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

        }

        // Overloaded constructor for MAT file load.
        GPU_Sparse ( matfile_load & mat_file, std::string variable ) {
            
            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);
            
            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = mat_var.sparsestream->ndata;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

            // Cast pointers to appropriate type.
            double * data_p = (double *) mat_var.sparsestream->data;
            int * i_p = (int *) mat_var.sparsestream->ir;
            int * j_p = (int *) mat_var.sparsestream->jc;

            // Initialize temporary vectors and fill them.
            thrust::device_vector<double> V_temp;
            thrust::device_vector<int> i_temp;
            thrust::device_vector<int> j_temp;
            V_temp.insert(V_temp.begin(),data_p,(data_p + Size[2]));
            i_temp.insert(i_temp.begin(),i_p,(i_p + Size[2]));
            j_temp.insert(j_temp.begin(),j_p,(j_p + Size[1] + 1));

            // Transpose the matrix and fill Values, I and J.
            spdtrans(V_temp,j_temp,i_temp,Values,I,J);

        }
};

class GPU_Sparse_f: private GPU_methods {
    public:
        // Based on cuSPARSE CSR three array zero based indexing.
        // https://docs.nvidia.com/cuda/cusparse/index.html#compressed-sparse-row-format-csr
        
        // Data
        thrust::device_vector<float> Values;  // Device vector of length Size[2] storing type float.
        int Size[3];                          // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;         // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;         // Device vector of length Size[2] storing type int.
        cusparseMatDescr_t descr = NULL;      // Matrix description.

        // Methods
        // Links to GPU_methods.fadd().
        GPU_Sparse_f add ( const float a ) {
            
            // Initialize result Vector.
            GPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call GPU_methods.fadd().
            y.Values = fadd(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spfadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        GPU_Sparse_f trans (  ) {
            
            GPU_Sparse_f result(Size[1],Size[0],Size[2]);

            spftrans(Values,I,J,result.Values,result.I,result.J);

            return result;

        }
        // Links to GPU_methods.fscp().
        GPU_Sparse_f scp ( const float a ) {
            
            // Initialize result Vector.
            GPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call GPU_methods.fscp().
            y.Values = fscp(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spfgemv().
        GPU_Dense_f mv ( const GPU_Dense_f& x ) {

            // Initialize result Vector.
            GPU_Dense_f y(Size[0],1);

            assert((Size[1] == x.Size[0]) && (x.isVector == 1));

            // Create pointers.
            const float * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ip = thrust::raw_pointer_cast(&I[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call GPU_methods.spdgemv().
            y.Values = spfgemv(Size[0],Size[1],Size[2],Vp,Ip,Jp,xp,descr);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Print the matrix.
        void print (  ) {

            // Transport to host memory.
            thrust::host_vector<float> V_temp = Values;
            thrust::host_vector<int> J_temp = J;
            thrust::host_vector<int> I_temp = I;

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Print first line.
            std::cout << "\n\tValues\t\t" << "(i,j)" << std::endl; 

            // Print.
            int l = 0;
            for (int k = 0; k < Size[2]; k++) {
                if (k == I_temp[l+1]) { l++; }
                std::cout << "\n\t" << V_temp[k] << "\t(" << l << "," << J_temp[k] << ")";
            } std::cout << "\n\n";

        }

        void save ( matfile_save & mat_file, std::string varname ) {

            // Create temporary transposed matrix.
            GPU_Sparse_f temp = trans();

            thrust::host_vector<double> V_temp = temp.Values;
            thrust::host_vector<int> i_temp = temp.I;
            thrust::host_vector<int> j_temp = temp.J;

            // Create pointer.
            double * V = thrust::raw_pointer_cast(&V_temp[0]);
            int * i = thrust::raw_pointer_cast(&i_temp[0]);
            int * j = thrust::raw_pointer_cast(&j_temp[0]);

            // Create MatIO Sparse stream. 
            matsparse_save sparse_temp(V,j,i,Size[2],Size[1]);

            // Write to MAT file.
            mat_file.save(varname,"sparse",sparse_temp.sparsestream,Size[0],Size[1]);

        }

        // Constructor
        GPU_Sparse_f ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

        }

        // Overloaded constructor for MAT file load.
        GPU_Sparse_f ( matfile_load & mat_file, std::string variable ) {

            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);
            
            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = mat_var.sparsestream->ndata;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

            // Cast pointers to appropriate type.
            double * data_p = (double *) mat_var.sparsestream->data;
            int * i_p = (int *) mat_var.sparsestream->ir;
            int * j_p = (int *) mat_var.sparsestream->jc;

            // Initialize temporary vectors and fill them.
            thrust::host_vector<double> V_temp; 
            thrust::device_vector<int> i_temp;
            thrust::device_vector<int> j_temp;
            V_temp.insert(V_temp.begin(),data_p,(data_p + Size[2]));
            i_temp.insert(i_temp.begin(),i_p,(i_p + Size[2]));
            j_temp.insert(j_temp.begin(),j_p,(j_p + Size[1] + 1));

            // Convert to float.
            thrust::host_vector<float> V_temp_ff = V_temp;
            thrust::device_vector<float> V_temp_f = V_temp_ff;
            
            // Transpose the matrix and fill Values, I and J.
            spftrans(V_temp_f,j_temp,i_temp,Values,I,J);

        }
};