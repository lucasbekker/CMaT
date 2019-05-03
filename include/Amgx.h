
struct AMGX_input_data {
    
    // Matrix A.
    GPU_Sparse   A_g();
    GPU_Sparse_f * A_gf;
    CPU_Sparse *  A_c;
    CPU_Sparse_f * A_cf;

    // Vector b.
    GPU_Dense *  b_g;
    GPU_Dense_f * b_gf;
    CPU_Dense *  b_c;
    CPU_Dense_f * b_cf;

    // Vector x (initial guess).
    GPU_Dense *  x_g;
    GPU_Dense_f * x_gf;
    CPU_Dense *  x_c;
    CPU_Dense_f * x_cf;

};

struct AMGX_output_data {

    // Vector x (result).
    GPU_Dense   x_g();
    GPU_Dense_f * x_gf;
    CPU_Dense *  x_c;
    CPU_Dense_f * x_cf;

};

class AmgX {
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
    AMGX_output_data download (  ) {

        // Output data container.
        AMGX_output_data out_vec;

        // Fill the correct element of the output data container.
        if ( mode == AMGX_mode_dDDI ) {
            //AMGX_vector_download(x,out_vec.x_g);
        } else if ( mode == AMGX_mode_dFFI ) {
            //AMGX_vector_download(x,out_vec.x_gf);
        } else if ( mode == AMGX_mode_hDDI ) {
            //AMGX_vector_download(x,out_vec.x_c);
        } else {
            //AMGX_vector_download(x,out_vec.x_cf);
        }

        // Return the output data container.
        return out_vec;
 
    }

    // Retrieve the input data.
    void upload ( AMGX_input_data in_data ) {
        
        // Fill A, b and x with the correct elements of the input data container.
        if ( mode == AMGX_mode_dDDI ) {
            //AMGX_matrix_upload_all(A, n, nnz, 1, 1, in_data.A_g.row_ptr, in_data.A_g.col_ind, in_data.A_g.data, 0);
            //AMGX_vector_upload(b, n, 1, in_data.b_g.data);
            //AMGX_vector_upload(x, n, 1, in_data.x_g.data);
        } else if ( mode == AMGX_mode_dFFI ) {
            //AMGX_matrix_upload_all(A, n, nnz, 1, 1, in_data.A_gf.row_ptr, in_data.A_gf.col_ind, in_data.A_gf.data, 0);
            //AMGX_vector_upload(b, n, 1, in_data.b_gf.data);
            //AMGX_vector_upload(x, n, 1, in_data.x_gf.data);
        } else if ( mode == AMGX_mode_hDDI ) {
            //AMGX_matrix_upload_all(A, n, nnz, 1, 1, in_data.A_c.row_ptr, in_data.A_c.col_ind, in_data.A_c.data, 0);
            //AMGX_vector_upload(b, n, 1, in_data.b_c.data);
            //AMGX_vector_upload(x, n, 1, in_data.x_c.data);
        } else {
            //AMGX_matrix_upload_all(A, n, nnz, 1, 1, in_data.A_cf.row_ptr, in_data.A_cf.col_ind, in_data.A_cf.data, 0);
            //AMGX_vector_upload(b, n, 1, in_data.b_cf.data);
            //AMGX_vector_upload(x, n, 1, in_data.x_cf.data);
        }

    }
    
    // Constructor.
    AmgX ( std::string input_config, AMGX_Mode input_mode ) {

        // Store the input.
        mode = input_mode;
        config_spec = input_config;

        // Initialize AMGX library.
        AMGX_initialize();
        AMGX_initialize_plugins();
        AMGX_install_signal_handler();

        // Create AMGX configuration, resources and solver.
        AMGX_config_create(&config, config_spec.c_str());
        AMGX_resources_create_simple(&resources, config);
        AMGX_solver_create(&solver, resources, mode, config);

        // Create the AMGX matrix and vectors.
        AMGX_matrix_create(&A, resources, mode);
        AMGX_vector_create(&b, resources, mode);
        AMGX_vector_create(&x, resources, mode);

    }

    // Destructor.
    ~AmgX (  ) {

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
};