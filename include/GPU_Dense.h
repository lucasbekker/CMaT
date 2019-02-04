class GPU_Dense: public GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.
        
        // Methods
        // Links to GPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ddot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ddgemv().
        GPU_Dense mv ( const GPU_Dense x ) {
            
            // Initialize result Vector.
            GPU_Dense y(Size[0],1);

            // Create pointers.
            const double * A = thrust::raw_pointer_cast(&Values[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.ddgemv().
            y.Values = this->ddgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

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
};

class GPU_Dense_f: public GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;   // Device vector of length Size[2] storing type float.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to GPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fdot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dfgemv().
        GPU_Dense_f mv ( GPU_Dense_f x ) {
            
            // Initialize result Vector.
            GPU_Dense_f y(Size[0],1);

            // Create pointers.
            const float * A = thrust::raw_pointer_cast(&Values[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.ddgemv().
            y.Values = this->dfgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to GPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

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
};