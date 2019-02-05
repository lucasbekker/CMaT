// Functor for fscp.
struct fscp_functor {
  
    const float a;

    fscp_functor( float _a ) : a( _a ) {}

        __host__ __device__
        float operator (  ) ( const float& x ) const {

            return a * x;

        }
};

// Functor for dscp.
struct dscp_functor {
                
const double a;

dscp_functor( double _a ) : a( _a ) {}

    __host__ __device__
    double operator (  ) ( const double& x ) const {

        return a * x;

    }
};