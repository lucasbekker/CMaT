// Struct containing cuBLAS/cuSPARSE handles/statuses.
struct HANDLES {
    cublasHandle_t cbhandle;
    cublasStatus_t cbstatus;
    cusparseHandle_t cshandle;
    cusparseStatus_t csstatus;
    bool isCreated = false;
};

// Function creating cuBLAS/cuSPARSE handles.
HANDLES createHandles (  ) {

    // Initialize cuBLAS/cuSPARSE handles/statuses.
    HANDLES handles;

    // Create cuBLAS handle and check status.
    handles.cbstatus = cublasCreate(&handles.cbhandle);
    if (handles.cbstatus != CUBLAS_STATUS_SUCCESS) {
    std::cout << "cuBLAS status is not ok. " << std::endl; }

    // Create cuSPARSE handle and check status.
    handles.csstatus = cusparseCreate(&handles.cshandle);
    if (handles.csstatus != CUSPARSE_STATUS_SUCCESS) {
    std::cout << "cuSPARSE status is not ok. " << std::endl; }

    // Set isCreated.
    if ((handles.cbstatus == CUBLAS_STATUS_SUCCESS) && 
        (handles.csstatus == CUSPARSE_STATUS_SUCCESS)) {
            handles.isCreated = true;
        } else { std::cout << "handles are not created properly." << std::endl; }

    return handles;
}

// Function to destroy cuBLAS/cuSPARSE handles.
void destroyHandles ( HANDLES handles ) {

    // Destroy the cuBLAS/cuSPARSE handles.
    cublasDestroy(handles.cbhandle);
    cusparseDestroy(handles.cshandle);

    // Set isCreated.
    handles.isCreated = false;
}