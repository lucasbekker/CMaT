#pragma once

extern int num_iter = 0;

struct SOLVER_data {
    
    // Matrix A.
    GPU_Sparse *   A_g;
    GPU_Sparse_f * A_gf;
    CPU_Sparse *   A_c;
    CPU_Sparse_f * A_cf;

    // Vector b.
    GPU_Dense *   b_g;
    GPU_Dense_f * b_gf;
    CPU_Dense *   b_c;
    CPU_Dense_f * b_cf;

    // Vector x.
    GPU_Dense *   x_g;
    GPU_Dense_f * x_gf;
    CPU_Dense *   x_c;
    CPU_Dense_f * x_cf;

    // Size parameters.
    int n;
    int nnz;

};

class SOLVER_AmgX {
    public:
    // Data
    // AMGX configuration specification.
    std::string config_spec;

    // AMGX handles.
    AMGX_config_handle config;
    AMGX_resources_handle resources;
    AMGX_solver_handle solver;
    AMGX_Mode mode;

    // AMGX problem data.
    int n;
    int nnz;
    AMGX_matrix_handle A;
    AMGX_vector_handle b;
    AMGX_vector_handle x;

    // Methods.
    // Setup and call the solver.
    void solve (  ) {

        // Solve Ax=b.
        AMGX_solver_setup(solver, A);
        AMGX_solver_solve(solver, b, x);

    }

    // Gather the result.
    void download ( SOLVER_data & Axb ) {

        // Initialize pointer.
        void * x_pointer = NULL;

        // Generate correct address.
        if ( mode == AMGX_mode_dDDI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_g->Values[0]));
        } else if ( mode == AMGX_mode_dFFI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_gf->Values[0]));            
        } else if ( mode == AMGX_mode_hDDI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_c->Values[0]));
        } else {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_cf->Values[0]));
        }
 
        // Store values of output vector.
        AMGX_vector_download(x, x_pointer);

    }

    // Retrieve the input data.
    void upload ( SOLVER_data & Axb ) {

        // Initialize pointers.
        int * A_row_ptr  = NULL;
        int * A_col_ind  = NULL;
        void * A_data    = NULL;
        void * b_pointer = NULL;
        void * x_pointer = NULL;

        // Initialize temporary I vector.
        thrust::host_vector<int> I_temp;
                
        // Generate correct addresses.
        if ( mode == AMGX_mode_dDDI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_g->Values[0]));
            b_pointer = (void *) thrust::raw_pointer_cast(&(Axb.b_g->Values[0]));
            A_data    = (void *) thrust::raw_pointer_cast(&(Axb.A_g->Values[0]));
            A_col_ind = thrust::raw_pointer_cast(&(Axb.A_g->J[0]));
            A_row_ptr = thrust::raw_pointer_cast(&(Axb.A_g->I[0]));
        } else if ( mode == AMGX_mode_dFFI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_gf->Values[0]));
            b_pointer = (void *) thrust::raw_pointer_cast(&(Axb.b_gf->Values[0]));
            A_data    = (void *) thrust::raw_pointer_cast(&(Axb.A_gf->Values[0]));
            A_col_ind = thrust::raw_pointer_cast(&(Axb.A_gf->J[0]));
            A_row_ptr = thrust::raw_pointer_cast(&(Axb.A_gf->I[0]));
        } else if ( mode == AMGX_mode_hDDI ) {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_c->Values[0]));
            b_pointer = (void *) thrust::raw_pointer_cast(&(Axb.b_c->Values[0]));
            A_data    = (void *) thrust::raw_pointer_cast(&(Axb.A_c->Values[0]));
            A_col_ind = thrust::raw_pointer_cast(&(Axb.A_c->J[0]));
            int * Ib_begin = thrust::raw_pointer_cast(&(Axb.A_c->Ib[0]));
            int * Ie_end   = thrust::raw_pointer_cast(&(Axb.A_c->Ie[(n - 1)]));
            I_temp.insert(I_temp.begin(),Ib_begin,(Ib_begin + n));
            I_temp.insert(I_temp.end(),Ie_end,(Ie_end + 1));
            A_row_ptr = thrust::raw_pointer_cast(&I_temp[0]);
        } else {
            x_pointer = (void *) thrust::raw_pointer_cast(&(Axb.x_cf->Values[0]));
            b_pointer = (void *) thrust::raw_pointer_cast(&(Axb.b_cf->Values[0]));
            A_data    = (void *) thrust::raw_pointer_cast(&(Axb.A_cf->Values[0]));
            A_col_ind = thrust::raw_pointer_cast(&(Axb.A_cf->J[0]));
            int * Ib_begin = thrust::raw_pointer_cast(&(Axb.A_cf->Ib[0]));
            int * Ie_end   = thrust::raw_pointer_cast(&(Axb.A_cf->Ie[(n - 1)]));
            I_temp.insert(I_temp.begin(),Ib_begin,(Ib_begin + n));
            I_temp.insert(I_temp.end(),Ie_end,(Ie_end + 1));
            A_row_ptr = thrust::raw_pointer_cast(&I_temp[0]);
        }
        
        // Upload A, b and x to AMGX.
        AMGX_matrix_upload_all(A, n, nnz, 1, 1, A_row_ptr, A_col_ind, A_data, 0);
        AMGX_vector_upload(b, n, 1, b_pointer);
        AMGX_vector_upload(x, n, 1, x_pointer);

    }

    // Clean the AMGX related objects.
    void destroy (  ) {

        // Destroy AMGX objects.
        AMGX_solver_destroy(solver);
        AMGX_matrix_destroy(A);
        AMGX_vector_destroy(b);
        AMGX_vector_destroy(x);
        AMGX_resources_destroy(resources);
        AMGX_config_destroy(config);

        // Finalize AMGX library.
        AMGX_reset_signal_handler();
        AMGX_finalize_plugins();
        AMGX_finalize();

    }
    
    // Constructor.
    SOLVER_AmgX ( std::string input_config, AMGX_Mode input_mode, SOLVER_data & Axb ) {

        // Store the input.
        n = Axb.n;
        nnz = Axb.nnz;
        mode = input_mode;
        config_spec = input_config;

        // Initialize AMGX library.
        AMGX_initialize();
        AMGX_initialize_plugins();
        AMGX_install_signal_handler();

        // Create AMGX configuration, resources and solver.
        AMGX_config_create_from_file(&config, config_spec.c_str());
        AMGX_resources_create_simple(&resources, config);
        AMGX_solver_create(&solver, resources, mode, config);

        // Create the AMGX matrix and vectors.
        AMGX_matrix_create(&A, resources, mode);
        AMGX_vector_create(&b, resources, mode);
        AMGX_vector_create(&x, resources, mode);

        // Upload the data.
        upload(Axb);

        // Solve Ax=b.
        solve();

        // Get the number of iterations
        AMGX_solver_get_iterations_number(solver,&num_iter);
        num_iter--;

        // Store the results.
        download(Axb);

    }

    // Destructor.
    ~SOLVER_AmgX (  ) {

        destroy();

    }
};

CPU_Dense CPU_Sparse::solve ( CPU_Dense & b, std::string config_spec ) {

    // Initialize output vector and fill with initial guess.
    CPU_Dense x = b.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_c = this;
    Axb.b_c = &b;
    Axb.x_c = &x;
    Axb.n = Size[0];
    Axb.nnz = Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hDDI;

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Return the output vector.
    return x;

}

CPU_Dense_f CPU_Sparse_f::solve ( CPU_Dense_f & b, std::string config_spec ) {

    // Initialize output vector and fill with initial guess.
    CPU_Dense_f x = b.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_cf = this;
    Axb.b_cf = &b;
    Axb.x_cf = &x;
    Axb.n = Size[0];
    Axb.nnz = Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hFFI;

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Return the output vector.
    return x;

}

GPU_Dense GPU_Sparse::solve ( GPU_Dense & b, std::string config_spec ) {

    // Initialize output vector and fill with initial guess.
    GPU_Dense x = b.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_g = this;
    Axb.b_g = &b;
    Axb.x_g = &x;
    Axb.n = Size[0];
    Axb.nnz = Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dDDI;

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Return the output vector.
    return x;

}

GPU_Dense GPU_Sparse::solve ( GPU_Dense & b, GPU_Dense & x0, std::string config_spec ) {

    // Initialize output vector and fill with initial guess.
    GPU_Dense x = x0.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_g = this;
    Axb.b_g = &b;
    Axb.x_g = &x;
    Axb.n = Size[0];
    Axb.nnz = Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dDDI;

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Return the output vector.
    return x;

}

GPU_Dense_f GPU_Sparse_f::solve ( GPU_Dense_f & b, std::string config_spec ) {

    // Initialize output vector and fill with initial guess.
    GPU_Dense_f x = b.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_gf = this;
    Axb.b_gf = &b;
    Axb.x_gf = &x;
    Axb.n = Size[0];
    Axb.nnz = Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dFFI;

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Return the output vector.
    return x;

}