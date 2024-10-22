#pragma once

class CPU_Dense: private CPU_methods {
    public:
        // Data
        thrust::host_vector<double> Values;    // Host vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.dadd().
        CPU_Dense add ( const double a ) {
            
            // Initialize result Vector.
            CPU_Dense y(Size[0],Size[1]);

            // Create pointers.
            const thrust::host_vector<double> * xp = &Values;

            // Call CPU_methods.dscp().
            y.Values = dadd(a,xp);

            // Return the result.
            return y;

        }

        // Adds two matrices.
        CPU_Dense add ( CPU_Dense B ) {

            // Initialize the resulting matrix.
            CPU_Dense A(Size[0],Size[1]);

            // Check the dimensions.
            if ((Size[0] == B.Size[0]) && (Size[1] == B.Size[1])) {

                thrust::transform(Values.begin(),Values.end(),B.Values.begin(),
                                  A.Values.begin(),thrust::plus<double>());

            } else { std::cout << "Dimension mismatch" << std::endl; }

            // Return the result.
            return A;

        }

        // Transposes the Matrix or Vector.
        CPU_Dense trans (  ) {

            // Initialize the resulting matrix.
            CPU_Dense A(Size[1],Size[0]);

            // Fill te resulting matrix with a copy of the data.
            thrust::copy(Values.begin(),Values.end(),A.Values.begin());

            // Create a temporary index array.
            thrust::host_vector<int> index(Values.size());

            // Fill the temporary array with the index information.
            thrust::tabulate(index.begin(),index.end(),modulus_functor(Size[0]));
            
            // Rearrange the values in the resulting matrix.
            thrust::stable_sort_by_key(index.begin(),index.end(),A.Values.begin());

            // Return the result.
            return A;

        }

        // Links to CPU_methods.dscp().
        CPU_Dense scp ( const double a ) {
            
            // Initialize result Vector.
            CPU_Dense y(Size[0],Size[1]);

            // Create pointers.
            const thrust::host_vector<double> * xp = &Values;

            // Call CPU_methods.dscp().
            y.Values = dscp(a,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.ddot().
        double dot ( const CPU_Dense& x ) {
            
            // Initialize the result.
            double result;

            // Check if the dimensions are correct.
            assert((isVector == 1) && (x.isVector == 1) && (Size[0] == x.Size[0])); 

            // Create pointers.
            const thrust::host_vector<double> * xp = &x.Values;
            const thrust::host_vector<double> * yp = &Values;

            // Call CPU_methods.ddot().
            result = ddot(xp,yp);

            // Return the result.
            return result;

        }

        // Links to CPU_methods.ddgemv().
        CPU_Dense mv ( const CPU_Dense& x ) {

            // Initialize result Vector.
            CPU_Dense y(Size[0],1);

            // Check if the dimensions are correct.
            assert((isVector == 0) && (x.isVector == 1) && (Size[1] == x.Size[0]));

            // Create pointers.
            const double * A = thrust::raw_pointer_cast(&Values[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.ddgemv().
            y.Values = ddgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;
            
        }

        // Links to CPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        CPU_Dense clone (  ) { 

            CPU_Dense c(Size[0],Size[1],isVector);

            c.Values = Values;

            return c;

        }

        // Print to stdout.
        void print (  ) {

            // Transpose the matrix to achieve row major layout.
            CPU_Dense A = trans();

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Loop over the elements to print.
            for (int k = 0; k < Size[2]; k++) {
                if ((k % Size[1]) == 0) { std::cout << "\n"; }
                std::cout << "\t" << A.Values[k];
            } std::cout << "\n\n"; 

        }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {
            
            // Create pointer.
            void * datap = thrust::raw_pointer_cast(&Values[0]);

            // Write to MAT file.
            mat_file.save(varname,"double",datap,Size[0],Size[1]);

        }

        // Constructor
        CPU_Dense ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        CPU_Dense ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }

        // Overloaded constructor for MAT file load.
        CPU_Dense ( matfile_load & mat_file, std::string variable ) {
            
            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);

            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = Size[0]*Size[1];

            // Insert the data into the Values vector.
            double * data_p = (double *) mat_var.varstream->data;
            Values.insert(Values.begin(),data_p,(data_p + Size[2]));

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }
};

class CPU_Dense_f: private CPU_methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
        int Size[3];                         // Array containing [ m, n, n*m ]
        int isVector;                        // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.fadd().
        CPU_Dense_f add ( const float a ) {
            
            // Initialize result Vector.
            CPU_Dense_f y(Size[0],Size[1]);

            // Create pointers.
            const thrust::host_vector<float> * xp = &Values;

            // Call CPU_methods.dscp().
            y.Values = fadd(a,xp);

            // Return the result.
            return y;

        }

        // Adds two matrices.
        CPU_Dense_f add ( CPU_Dense_f B ) {

            // Initialize the resulting matrix.
            CPU_Dense_f A(Size[0],Size[1]);

            // Check the dimensions.
            if ((Size[0] == B.Size[0]) && (Size[1] == B.Size[1])) {

                thrust::transform(Values.begin(),Values.end(),B.Values.begin(),
                                  A.Values.begin(),thrust::plus<float>());

            } else { std::cout << "Dimension mismatch" << std::endl; }

            // Return the result.
            return A;

        }

        // Transposes the Matrix or Vector.
        CPU_Dense_f trans (  ) {

            // Initialize the resulting matrix.
            CPU_Dense_f A(Size[1],Size[0]);

            // Fill te resulting matrix with a copy of the data.
            thrust::copy(Values.begin(),Values.end(),A.Values.begin());

            // Create a temporary index array.
            thrust::host_vector<int> index(Values.size());

            // Fill the temporary array with the index information.
            thrust::tabulate(index.begin(),index.end(),modulus_functor(Size[0]));
            
            // Rearrange the values in the resulting matrix.
            thrust::stable_sort_by_key(index.begin(),index.end(),A.Values.begin());

            // Return the result.
            return A;

        }

        // Links to CPU_methods.fscp().
        CPU_Dense_f scp ( const float a ) {
            
            // Initialize result Vector.
            CPU_Dense_f y(Size[0],Size[1]);

            // Create pointers.
            const thrust::host_vector<float> * xp = &Values;

            // Call CPU_methods.fscp().
            y.Values = fscp(a,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.fdot().
        float dot ( const CPU_Dense_f& x ) {

            // Initialize the result.
            float result;

            // Check if the dimensions are correct.
            assert((isVector == 1) && (x.isVector == 1) && (Size[0] == x.Size[0]));

            // Create pointers.
            const thrust::host_vector<float> * xp = &x.Values;
            const thrust::host_vector<float> * yp = &Values;

            // Call CPU_methods.fdot().
            result = fdot(xp,yp);

            // Return the result.
            return result;

        }

        // Links to CPU_methods.dfgemv().
        CPU_Dense_f mv ( CPU_Dense_f& x ) {
            
            // Initialize result Vector.
            CPU_Dense_f y(Size[0],1);

            // Check if the dimensions are correct.
            assert((isVector == 0) && (x.isVector == 1) && (Size[1] == x.Size[0]));

            // Create pointers.
            const float * A = thrust::raw_pointer_cast(&Values[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.dfgemv().
            y.Values = dfgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        CPU_Dense_f clone (  ) { 

            CPU_Dense_f c(Size[0],Size[1],isVector);

            c.Values = Values;

            return c;

        }

        // Print to stdout.
        void print (  ) {

            // Transpose the matrix to achieve row major layout.
            CPU_Dense_f A = trans();

            // Set the print specifications.
            std::cout.precision(6);
            std::cout << std::scientific;

            // Loop over the elements to print.
            for (int k = 0; k < Size[2]; k++) {
                if ((k % Size[1]) == 0) { std::cout << "\n"; }
                std::cout << "\t" << A.Values[k];
            } std::cout << "\n\n"; 

        }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {
            
            // Create pointer.
            void * datap = thrust::raw_pointer_cast(&Values[0]);

            // Write to MAT file.
            mat_file.save(varname,"float",datap,Size[0],Size[1]);

        }

        // Constructor
        CPU_Dense_f ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        CPU_Dense_f ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }

        // Overloaded constructor for MAT file load.
        CPU_Dense_f ( matfile_load & mat_file, std::string variable ) {
            
            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);

            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[1];
            Size[2] = Size[0]*Size[1];

            // Insert the data into the Values vector.
            float * data_p = (float *) mat_var.varstream->data;
            Values.insert(Values.begin(),data_p,(data_p + Size[2]));

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

};