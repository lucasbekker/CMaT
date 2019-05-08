#pragma once

// Class containing the handles and status of the cuBLAS and cuSPARSE libraries.

class HANDLES {
    public:
        // cuBLAS handle and status.
        cublasHandle_t cbhandle;
        cublasStatus_t cbstatus;

        // cuSPARSE handle and status.
        cusparseHandle_t cshandle;
        cusparseStatus_t csstatus;

    // Constructor.
    HANDLES (  ) {

        // Create cuBLAS handle and check status.
        cbstatus = cublasCreate(&cbhandle);
        if (cbstatus != CUBLAS_STATUS_SUCCESS) {
        std::cout << "cuBLAS status is not ok. " << std::endl; }

        // Create cuSPARSE handle and check status.
        csstatus = cusparseCreate(&cshandle);
        if (csstatus != CUSPARSE_STATUS_SUCCESS) {
        std::cout << "cuSPARSE status is not ok. " << std::endl; }

    }

    // Destructor.
    ~HANDLES (  ) {

        // Destroy the cuBLAS/cuSPARSE handles.
        cublasDestroy(cbhandle);
        cusparseDestroy(cshandle);

    }

};

// Create the handles and pointers globally.
HANDLES handles;
HANDLES * _handles = &handles;