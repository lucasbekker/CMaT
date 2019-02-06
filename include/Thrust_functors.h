// Functor for fscp.
struct fscp_functor {
    
    // Local data.
    const float a;

    // Constructor, initialize "a" with value of alpha.
    fscp_functor( float alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    float operator () ( const float& x ) const { return a * x; }

};

// Functor for dscp.
struct dscp_functor {

    // Local data.           
    const double a;

    // Constructor, initialize "a" with value of alpha.
    dscp_functor( double alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    double operator () ( const double& x ) const { return a * x; }

};

// Functor for fadd.
struct fadd_functor {
    
    // Local data.
    const float a;

    // Constructor, initialize "a" with value of alpha.
    fadd_functor( float alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    float operator () ( const float& x ) const { return a + x; }

};

// Functor for dadd.
struct dadd_functor {

    // Local data.           
    const double a;

    // Constructor, initialize "a" with value of alpha.
    dadd_functor( double alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    double operator () ( const double& x ) const { return a + x; }

};

// Functor for fscp.
struct fscp_m_functor {
    
    // Local data.
    const float a;

    // Constructor, initialize "a" with value of alpha.
    fscp_m_functor( float alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    float operator () ( const float& x ) const { return -a * x; }

};

// Functor for dscp.
struct dscp_m_functor {

    // Local data.           
    const double a;

    // Constructor, initialize "a" with value of alpha.
    dscp_m_functor( double alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    double operator () ( const double& x ) const { return -a * x; }

};

// Functor for fadd.
struct fadd_m_functor {
    
    // Local data.
    const float a;

    // Constructor, initialize "a" with value of alpha.
    fadd_m_functor( float alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    float operator () ( const float& x ) const { return x - a; }

};

// Functor for dadd.
struct dadd_m_functor {

    // Local data.           
    const double a;

    // Constructor, initialize "a" with value of alpha.
    dadd_m_functor( double alpha ): a(alpha) {  }

    // Overload the () operator.
    __host__ __device__
    double operator () ( const double& x ) const { return x - a; }

};