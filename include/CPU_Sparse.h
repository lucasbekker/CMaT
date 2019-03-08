class CPU_Sparse: private CPU_methods {
    public:
        // Based on MKL CSR four array zero based indexing.
        // https://software.intel.com/en-us/mkl-developer-reference-c-sparse-blas-csr-matrix-storage-format

        // Data
        thrust::host_vector<double> Values;  // Host vector of length Size[2] storing type double.
        int Size[3];                         // Array containing [ m, n, nnz ]
        thrust::host_vector<int> Ib;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> Ie;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> J;          // Host vector of length Size[2] storing type int.

        // Methods
        // Links to CPU_methods.dadd().
        CPU_Sparse add ( const double a ) {
            
            // Initialize result Vector.
            CPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::host_vector<double> * xp = &Values;

            // Call GPU_methods.dadd().
            y.Values = dadd(a,xp);

            // Fill the index arrays.
            y.Ib = Ib;
            y.Ie = Ie;
            y.J = J;

            // Return the result.
            return y;

        }
        
        // Links to CPU_methods.spdadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        CPU_Sparse trans (  ) {
            
            CPU_Sparse result(Size[1],Size[0],Size[2]);

            spdtrans(Values,Ib,Ie,J,result.Values,result.Ib,result.Ie,result.J);

            return result;

        }

        // Links to CPU_methods.dscp().
        CPU_Sparse scp ( const double a ) {
            
            // Initialize result Vector.
            CPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::host_vector<double> * xp = &Values;

            // Call GPU_methods.dscp().
            y.Values = dscp(a,xp);

            // Fill the index arrays.
            y.Ib = Ib;
            y.Ie = Ie;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spdgemv().
        CPU_Dense mv ( const CPU_Dense& x  ) {

            // Initialize result Vector.
            CPU_Dense y(Size[0],1);

            // Check if the dimensions are correct.
            assert((Size[1] == x.Size[0]) && (x.isVector == 1));
            
            // Create pointers.
            const double * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ibp = thrust::raw_pointer_cast(&Ib[0]);
            const int * Iep = thrust::raw_pointer_cast(&Ie[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.spdgemv().
            y.Values = spdgemv(Size[0],Size[1],Vp,Ibp,Iep,Jp,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Print the matrix.
        void print (  ) {

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Print first line.
            std::cout << "\n\tValues\t\t" << "(i,j)" << std::endl; 

            // Print.
            int l = 0;
            for (int k = 0; k < Size[2]; k++) {
                if (k == Ie[l]) { l++; }
                std::cout << "\n\t" << Values[k] << "\t(" << l << "," << J[k] << ")";
            } std::cout << "\n\n";

        }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {

            // Create temporary transposed matrix.
            CPU_Sparse temp = trans();

            // Convert Ib and Ie to generic Ip.
            temp.Ib.push_back(temp.Ie[(temp.Ie.size() - 1)]);

            // Create pointer.
            double * V = thrust::raw_pointer_cast(&temp.Values[0]);
            int * i = thrust::raw_pointer_cast(&temp.Ib[0]);
            int * j = thrust::raw_pointer_cast(&temp.J[0]);

            // Create MatIO Sparse stream. 
            matsparse_save sparse_temp(V,j,i,Size[2],Size[1]);

            // Write to MAT file.
            mat_file.save(varname,"sparse",sparse_temp.sparsestream,Size[0],Size[1]);

        }

        // Constructor
        CPU_Sparse ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);

        }

        // Overloaded constructor for MAT file load.
        CPU_Sparse ( matfile_load & mat_file, std::string variable ) {

            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);
            
            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = mat_var.sparsestream->ndata;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);

            // Cast pointers to appropriate type.
            double * data_p = (double *) mat_var.sparsestream->data;
            int * i_p = (int *) mat_var.sparsestream->ir;
            int * j_p = (int *) mat_var.sparsestream->jc;

            // Initialize temporary vectors and fill them.
            thrust::host_vector<double> V_temp; 
            thrust::host_vector<int> i_temp;
            thrust::host_vector<int> jb_temp;
            thrust::host_vector<int> je_temp;
            V_temp.insert(V_temp.begin(),data_p,(data_p + Size[2]));
            i_temp.insert(i_temp.begin(),i_p,(i_p + Size[2]));
            jb_temp.insert(jb_temp.begin(),j_p,(j_p + Size[1]));
            je_temp.insert(je_temp.begin(),(j_p + 1),(j_p + Size[1] + 1));

            // Transpose the matrix and fill Values, I and J.
            spdtrans(V_temp,jb_temp,je_temp,i_temp,Values,Ib,Ie,J);

        }

};

class CPU_Sparse_f: private CPU_methods {
    public:
        // Based on MKL CSR four array zero based indexing.
        // https://software.intel.com/en-us/mkl-developer-reference-c-sparse-blas-csr-matrix-storage-format

        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
        int Size[3];                         // Array containing [ m, n, nnz ]
        thrust::host_vector<int> Ib;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> Ie;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> J;          // Host vector of length Size[2] storing type int.

        // Methods
        // Links to CPU_methods.fadd().
        CPU_Sparse_f add ( const float a ) {
            
            // Initialize result Vector.
            CPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::host_vector<float> * xp = &Values;

            // Call GPU_methods.fadd().
            y.Values = fadd(a,xp);

            // Fill the index arrays.
            y.Ib = Ib;
            y.Ie = Ie;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spfadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        CPU_Sparse_f trans (  ) {
            
            CPU_Sparse_f result(Size[1],Size[0],Size[2]);

            spftrans(Values,Ib,Ie,J,result.Values,result.Ib,result.Ie,result.J);

            return result;

        }

        // Links to CPU_methods.fscp().
        CPU_Sparse_f scp ( const float a ) {
            
            // Initialize result Vector.
            CPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::host_vector<float> * xp = &Values;

            // Call GPU_methods.fscp().
            y.Values = fscp(a,xp);

            // Fill the index arrays.
            y.Ib = Ib;
            y.Ie = Ie;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spfgemv().
        CPU_Dense_f mv ( const CPU_Dense_f& x  ) {

            // Initialize result Vector.
            CPU_Dense_f y(Size[0],1);

            // Check if the dimensions are correct.
            assert((Size[1] == x.Size[0]) && (x.isVector == 1));
            
            // Create pointers.
            const float * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ibp = thrust::raw_pointer_cast(&Ib[0]);
            const int * Iep = thrust::raw_pointer_cast(&Ie[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.spfgemv().
            y.Values = spfgemv(Size[0],Size[1],Vp,Ibp,Iep,Jp,xp);

            // Return the result.
            return y;

        }
        // Links to CPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Print the matrix.
        void print (  ) {

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Print first line.
            std::cout << "\n\tValues\t\t" << "(i,j)" << std::endl; 

            // Print.
            int l = 0;
            for (int k = 0; k < Size[2]; k++) {
                if (k == Ie[l]) { l++; }
                std::cout << "\n\t" << Values[k] << "\t(" << l << "," << J[k] << ")";
            } std::cout << "\n\n";

        }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {

            // Create temporary transposed matrix.
            CPU_Sparse_f temp = trans();

            // Convert Ib and Ie to generic Ip.
            temp.Ib.push_back(temp.Ie[(temp.Ie.size() - 1)]);

            // Convert float to double.
            thrust::host_vector<double> V_temp = temp.Values;

            // Create pointer.
            double * V = thrust::raw_pointer_cast(&V_temp[0]);
            int * i = thrust::raw_pointer_cast(&temp.Ib[0]);
            int * j = thrust::raw_pointer_cast(&temp.J[0]);

            // Create MatIO Sparse stream. 
            matsparse_save sparse_temp(V,j,i,Size[2],Size[1]);

            // Write to MAT file.
            mat_file.save(varname,"sparse",sparse_temp.sparsestream,Size[0],Size[1]);

        }

        // Constructor
        CPU_Sparse_f ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);

        }

        // Overloaded constructor for MAT file load.
        CPU_Sparse_f ( matfile_load & mat_file, std::string variable ) {

            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);
            
            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = mat_var.sparsestream->ndata;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);
            
            // Cast pointers to appropriate type.
            double * data_p = (double *) mat_var.sparsestream->data;
            int * i_p = (int *) mat_var.sparsestream->ir;
            int * j_p = (int *) mat_var.sparsestream->jc;

            // Initialize temporary vectors and fill them.
            thrust::host_vector<double> V_temp; 
            thrust::host_vector<int> i_temp;
            thrust::host_vector<int> jb_temp;
            thrust::host_vector<int> je_temp;
            V_temp.insert(V_temp.begin(),data_p,(data_p + Size[2]));
            i_temp.insert(i_temp.begin(),i_p,(i_p + Size[2]));
            jb_temp.insert(jb_temp.begin(),j_p,(j_p + Size[1]));
            je_temp.insert(je_temp.begin(),(j_p + 1),(j_p + Size[1] + 1));

            // Convert to float.
            thrust::host_vector<float> V_temp_f = V_temp;

            // Transpose the matrix and fill Values, I and J.
            spftrans(V_temp_f,jb_temp,je_temp,i_temp,Values,Ib,Ie,J);

        }
};