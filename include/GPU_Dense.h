class GPU_Dense: private GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.
        
        // Methods
        // Links to GPU_methods.dadd().
        GPU_Dense add ( const double a ) {
            
            // Initialize result Vector.
            GPU_Dense y(Size[0],Size[1]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call CPU_methods.dscp().
            y.Values = dadd(a,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.dadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dscp().
        GPU_Dense scp ( const double a ) {
            
            // Initialize result Vector.
            GPU_Dense y(Size[0],Size[1]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call GPU_methods.dscp().
            y.Values = dscp(a,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.ddot().
        double dot ( const GPU_Dense& x ) {

            // Initialize the result.
            double result;

            // Check if the dimensions are correct.
            assert((isVector == 1) && (x.isVector == 1) && (Size[0] == x.Size[0]));

            // Create pointers.
            const thrust::device_vector<double> * xp = &x.Values;
            const thrust::device_vector<double> * yp = &Values;

            // Call GPU_methods.ddot().
            result = ddot(xp,yp);

            // Return the result.
            return result;

        }

        // Links to GPU_methods.ddgemv().
        GPU_Dense mv ( const GPU_Dense& x ) {
            
            // Initialize result Vector.
            GPU_Dense y(Size[0],1);

            // Check if the dimensions are correct.
            assert((isVector == 0) && (x.isVector == 1) && (Size[1] == x.Size[0]));

            // Create pointers.
            const double * A = thrust::raw_pointer_cast(&Values[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call GPU_methods.ddgemv().
            y.Values = ddgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {
            
            // Create pointer.
            void * datap = thrust::raw_pointer_cast(&Values[0]);

            // Write to MAT file.
            mat_file.save(varname,"double",datap,Size[0],Size[1]);

        }

        // Constructor
        GPU_Dense ( int m, int n ) {
            
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
        GPU_Dense ( int m, int n, int isv ) {
            
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
        GPU_Dense ( matfile_load & mat_file, std::string variable ) {
            
            // Open the variable in MAT file.
            matvar_load mat_var = mat_file.openvar(variable);

            // Fill Size array.
            Size[0] = mat_var.varstream->dims[0];
            Size[1] = mat_var.varstream->dims[0];
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

class GPU_Dense_f: private GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;   // Device vector of length Size[2] storing type float.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to GPU_methods.fadd().
        GPU_Dense_f add ( const float a ) {
            
            // Initialize result Vector.
            GPU_Dense_f y(Size[0],Size[1]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call CPU_methods.dscp().
            y.Values = fadd(a,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.fadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fscp().
        GPU_Dense_f scp ( const float a ) {
            
            // Initialize result Vector.
            GPU_Dense_f y(Size[0],Size[1]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call GPU_methods.fscp().
            y.Values = fscp(a,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.fdot().
        float dot ( const GPU_Dense_f& x ) {

            // Initialize the result.
            float result;

            // Check if the dimensions are correct.
            assert((isVector == 1) && (x.isVector == 1) && (Size[0] == x.Size[0]));

            // Create pointers.
            const thrust::device_vector<float> * xp = &x.Values;
            const thrust::device_vector<float> * yp = &Values;

            // Call GPU_methods.fdot().
            result = fdot(xp,yp);

            // Return the result.
            return result;
            
        }

        // Links to GPU_methods.dfgemv().
        GPU_Dense_f mv ( GPU_Dense_f& x ) {
            
            // Initialize result Vector.
            GPU_Dense_f y(Size[0],1);

            // Check if the dimensions are correct.
            assert((isVector == 0) && (x.isVector == 1) && (Size[1] == x.Size[0]));

            // Create pointers.
            const float * A = thrust::raw_pointer_cast(&Values[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call GPU_methods.dfgemv().
            y.Values = dfgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Save to MAT file.
        void save ( matfile_save & mat_file, std::string varname ) {
            
            // Create pointer.
            void * datap = thrust::raw_pointer_cast(&Values[0]);

            // Write to MAT file.
            mat_file.save(varname,"float",datap,Size[0],Size[1]);

        }

        // Constructor
        GPU_Dense_f ( int m, int n ) {
            
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
        GPU_Dense_f ( int m, int n, int isv ) {
            
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
        GPU_Dense_f ( matfile_load & mat_file, std::string variable ) {
            
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