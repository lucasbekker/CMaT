// CPU backend base class.
class CPU {
    public:
        // Methods
        void conv (  ) {}

        void ialloc (  ) {}

        void falloc (  ) {}

        void dalloc (  ) {}

        void dt (  ) {}

        void spgemm (  ) {}

        void spgemv (  ) {}

        void fgemm (  ) {}

        void fgemv (  ) {}
    };

// GPU backend base class.
class GPU {
    public:
        // Methods
        void conv (  ) {}

        void ialloc (  ) {}

        void falloc (  ) {}

        void dalloc (  ) {}
        
        void dt (  ) {}

        void spgemm (  ) {}

        void spgemv (  ) {}

        void fgemm (  ) {}

        void fgemv (  ) {}
    };
