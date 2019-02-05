class CPU_Dense: public CPU_methods {
    public:
        // Data
        thrust::host_vector<double> Values;    // Host vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.ddot().
        double dot ( const CPU_Dense& x ) {
            
            // Create pointers.
            const thrust::host_vector<double> * xp = &x.Values;
            const thrust::host_vector<double> * yp = &Values;

            // Call CPU_methods.ddot().
            double result = ddot(xp,yp);

            // Return the result.
            return result;

        }

        // Links to CPU_methods.ddgemv().
        CPU_Dense mv ( const CPU_Dense& x ) {

            // Initialize result Vector.
            CPU_Dense y(Size[0],1);

            // Create pointers.
            const double * A = thrust::raw_pointer_cast(&Values[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.ddgemv().
            y.Values = this->ddgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

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
};

class CPU_Dense_f: public CPU_methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
        int Size[3];                         // Array containing [ m, n, n*m ]
        int isVector;                        // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fdot().
        float dot ( const CPU_Dense_f& x ) {

            // Create pointers.
            const thrust::host_vector<float> * xp = &x.Values;
            const thrust::host_vector<float> * yp = &Values;

            // Call CPU_methods.ddot().
            float result = fdot(xp,yp);

            // Return the result.
            return result;

        }

        // Links to CPU_methods.dfgemv().
        CPU_Dense_f mv ( CPU_Dense_f& x ) {
            
            // Initialize result Vector.
            CPU_Dense_f y(Size[0],1);

            // Create pointers.
            const float * A = thrust::raw_pointer_cast(&Values[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.ddgemv().
            y.Values = this->dfgemv(Size[0],Size[1],A,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

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
};