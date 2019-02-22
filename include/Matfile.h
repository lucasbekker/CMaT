// Class definition of a variable in a MAT file to load.
class matvar_load {
    public:
        // Data
        matvar_t * varstream;                   // MatIO stream of the variable.
        mat_sparse_t * sparsestream;            // Empty if "matvar_load.issparse=false".
        std::string type;                       // Data type of the variable. (double, float or unsupported)
        bool issparse = false;                  // True if varstream contains a sparse variable.
    
        // Destructor
        ~matvar_load (  ) {

            // Free the variable.
            Mat_VarFree(varstream);
            
        }
};

// Class definition of a MAT file from which to load variables.
class matfile_load {
    public:
        // Data
        // Path data.
        std::string path;                       // Path to MAT file to load.
        std::string name;                       // Name of MAT file to load.
        std::string full_name;                  // path + name of MAT file to load.

        // Variable data
        std::list<std::string> varlist;         // List containing the variable names in MAT file to load.
        std::list<std::string> typelist;        // List containing the variable types in MAT file to load.
        std::list<std::string> issparselist;    // List containing the variable "issparse" in MAT file to load.
        int nvars = 0;                          // Number of variables of MAT file to load.

        // Stream data.
        mat_t * mat_file;                       // MatIO stream of MAT file to load.
        int status;                             // Status of MatIO stream to load.
        
        // Methods
        // Fill varlist with the properties of the variables in the Mat file.
        void getvarprops (  ) {

            // Open the first variable.
            matvar_t * varstream = Mat_VarReadNext(mat_file);

            // Loop over the variables.
            while ( varstream != NULL ) {

                // Check if the variable is sparse and store the result.
                if (varstream->class_type == 5) { issparselist.push_back("true");
                } else { issparselist.push_back("false"); }

                // Check if the variable is of type double or float and store the result.
                if (varstream->data_type == 9) { typelist.push_back("double"); 
                } else if (varstream->data_type == 7) { typelist.push_back("float"); 
                } else { typelist.push_back("unsupported"); }

                // Store the variable name.
                varlist.push_back(varstream->name);
                
                // Add one to the variable counter.
                nvars = nvars + 1;

                // Free the current variable.
                Mat_VarFree(varstream);

                // Load the new variable.
                varstream = Mat_VarReadNext(mat_file);

            }

            // Reset the MatIO stream.
            Mat_Rewind(mat_file);

        }

        // Print the content of varlist. 
        void printvarprops (  ) {

            // Declare the iterators.
            std::list<std::string>::iterator t_it = typelist.begin();
            std::list<std::string>::iterator s_it = issparselist.begin();
            std::list<std::string>::iterator v_it = varlist.begin();

            // Loop over the elements in varlist.
            while ( (v_it != varlist.end()) || (t_it != typelist.end()) ||
                (s_it != issparselist.end()) ) {
                
                // Print the properties.
                std::cout << "Variable " << *v_it << "\t type: "
                          << *t_it << "\t\t issparse: " << *s_it << std::endl;

                // Advance the iterators.
                ++v_it; ++t_it; ++s_it;

            }

        }

        // Open a variable in the MAT file.
        matvar_load openvar ( std::string variable ) {
            
            // Initialize matvar.
            matvar_load mat_var;

            // Open variable in .mat file.
            mat_var.varstream = Mat_VarRead(mat_file,variable.c_str());

            // Check succesfull opening of variable in .mat file.
            if (mat_var.varstream == NULL) {
                std::cout << "Variable: '" << variable << "' not found." << std::endl; 
            } else {

                // Check if the variable is sparse.
                if (mat_var.varstream->class_type == 5) {
                    mat_var.issparse = true;
                    mat_var.sparsestream = (mat_sparse_t *) mat_var.varstream->data;
                }

                // Check if the variable is of type double or float.
                if (mat_var.varstream->data_type == 9) { mat_var.type = "double"; }
                if (mat_var.varstream->data_type == 7) { mat_var.type = "float"; }
                
            }

            // Reset the MatIO stream.
            Mat_Rewind(mat_file);

            // Return the MAT variable.
            return mat_var;

        }

        // Constructor
        matfile_load ( std::string NAME ) {

            // Specify name and path.
            name = NAME;
            path = "WORK_DIR/";
            full_name = path + name;

            // Open the MAT file stream.
            mat_file = Mat_Open(name.c_str(),MAT_ACC_RDONLY);

            // Check succesfull opening of MAT file.
            if (mat_file == NULL) {
                std::cout << "Error opening MAT file: '" << name << "'" << std::endl;
                status = 0;
            } else { status = 1; }

            // Fill variables list.
            if ( status == 1 ) { getvarprops(); }

        }

        // Overloaded constructor for path specification. 
        matfile_load ( std::string PATH, std::string NAME ) {

            // Specify name and path.
            name = NAME;
            path = PATH;
            full_name = full_name = path + "/" + name;          

            // Open the MAT file stream.
            mat_file = Mat_Open(full_name.c_str(),MAT_ACC_RDONLY);

            // Check succesfull opening of MAT file.
            if (mat_file == NULL) {
                std::cout << "Error opening MAT file: '" << full_name << "'" << std::endl;
                status = 0;
            } else { status = 1; }

            // Fill variables list.
            if ( status == 1 ) { getvarprops(); }

        }

        // Destructor
        ~matfile_load (  ) {

            // Close the MAT file stream.
            Mat_Close(mat_file);

        }

};

// Class definition as a wrapper for mat_sparse_t.
class matsparse_save {
    public:
        // Data
        mat_sparse_t sparsestreamdata;
        mat_sparse_t * sparsestream = &sparsestreamdata;
        
        // Methods
        void matsparse_save_sub ( int * i, int * j, int numnz, int n ) {

            // Fill the data of sparsestream.
            sparsestream->nzmax = numnz;
            sparsestream->ndata = numnz;
            sparsestream->nir = numnz;
            sparsestream->njc = (n + 1);
            sparsestream->ir = (mat_int32_t *) i;
            sparsestream->jc = (mat_int32_t *) j;

        }

        // Constructor
        matsparse_save ( double * V, int * i, int * j, int numnz, int n ) {

            // Fill the data of sparsestream.
            matsparse_save_sub(i,j,numnz,n);
            sparsestream->data = V; 
            
        }

        // Overloaded constructor for float
        matsparse_save ( float * V, int * i, int * j, int numnz, int n ) {

            // Fill the data of sparsestream.
            matsparse_save_sub(i,j,numnz,n);
            sparsestream->data = (void *) V;

        }

};

// Class definition of a MAT file in which to save variables.
class matfile_save {
    public:
        // Data
        // Path data.
        std::string path;                       // Path to MAT file to load.
        std::string name;                       // Name of MAT file to load.
        std::string full_name;                  // path + name of MAT file to load.

        std::list<std::string> varlist;         // List containing the variable names in MAT file to save.
        mat_t * mat_file;                       // MatIO stream of MAT file to save.
        int status;                             // Status of MatIO stream to save.

        // Methods
        // Write data to a MAT file.
        void save ( std::string varname, std::string type, void * datap, int m, int n ) {

            // Check the variable name.
            varcheck(varname);
            
            // Store dimension data in the required format.
            size_t dims[2]; dims[0] = (size_t) m; dims[1] = (size_t) n;

            // Declare mat_var.
            matvar_t * mat_var;

            // Create the MAT file variable.
            if ( type == "double" ) {
                mat_var = Mat_VarCreate(varname.c_str(),MAT_C_DOUBLE,
                                        MAT_T_DOUBLE,2,dims,datap,0);
            } else if ( type == "float" ) {
                mat_var = Mat_VarCreate(varname.c_str(),MAT_C_SINGLE,
                                        MAT_T_SINGLE,2,dims,datap,0);
            } else if ( type == "sparsed" ) { 
                mat_var = Mat_VarCreate(varname.c_str(),MAT_C_SPARSE,
                                        MAT_T_DOUBLE,2,dims,datap,0);
            } else if ( type == "sparsef" ) { 
                mat_var = Mat_VarCreate(varname.c_str(),MAT_C_SPARSE,
                                        MAT_T_SINGLE,2,dims,datap,0);
            } else { mat_var = NULL; }

            // Check for errors, add to variable list and save the result.                                   
            if ( mat_var == NULL ) {

                // Error message.
                std::cout << "Error creating variable \"" << varname << "\"" 
                          << std::endl;

                // Change status.
                status = 0;

            } else if ( status == 1 ) {

                // Add name of variable to varlist.
                varlist.push_back(varname);

                // Write the variable to the MAT file.
                Mat_VarWrite(mat_file,mat_var,MAT_COMPRESSION_NONE);

                // Free the variable.
                Mat_VarFree(mat_var);

            }

        }

        // Check if the variable exists in the MAT file to save.
        void varcheck ( std::string varname ) {
            
            // Declare the iterators.           
            std::list<std::string>::iterator it = varlist.begin();

            // Loop over the variable list.
            while ( it != varlist.end() ) {

                // Check if varname is in varlist.
                if ( *it == varname ) { 
                    
                    // Set status to zero and print error message.
                    std::cout << "Variable name: " << varname 
                              << " already exists in MAT file." << std::endl;

                    status = 0;

                }

                // Advance the iterator.
                ++it;

            }

        }

        // Manual closing of MAT file.
        void close (  ) {

            // Close the MAT file.
            Mat_Close(mat_file);

        }

        // Constructor.
        matfile_save ( std::string NAME ) {

            // Store filename.
            name = NAME;
            path = "WORK_DIR/";
            full_name = path + name;

            // Create MAT file and check status.
            mat_file = Mat_CreateVer(name.c_str(),NULL,MAT_FT_DEFAULT);
            if ( NULL == mat_file ) {
                std::cout << "Error creating MAT file \"" << name << "\"" << std::endl;
                status = 0;
            } else { status = 1; }

        }

        // Overloaded constructor for path specification.
        matfile_save ( std::string PATH, std::string NAME ) {

            // Store filename.
            name = NAME;
            path = PATH;
            full_name = path + "/" + name;

            // Create MAT file and check status.
            mat_file = Mat_CreateVer(full_name.c_str(),NULL,MAT_FT_DEFAULT);
            if ( NULL == mat_file ) {
                std::cout << "Error creating MAT file \"" << name << "\"" << std::endl;
                status = 0;
            } else { status = 1; }

        }

        // Destructor
        ~matfile_save (  ) {

            // Close the MAT file.
            Mat_Close(mat_file);

        }

};