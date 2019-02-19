// Struct used in matfile_load.
struct matvar {

    matvar_t * varstream;                   // MatIO variable.
    mat_sparse_t * sparsestream;            // Only contains data if "matvar.issparse=true".
    std::string type;                       // Double, float or unsupported.
    bool issparse = false;                  // True if varstream is a sparse variable.
    
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
            matvar_t * mat_var = Mat_VarReadNext(mat_file);

            // Loop over the variables.
            while ( mat_var != NULL ) {

                // Check if the variable is sparse and store the result.
                if (mat_var->class_type == 5) { issparselist.push_back("true");
                } else { issparselist.push_back("false"); }

                // Check if the variable is of type double or float and store the result.
                if (mat_var->data_type == 9) { typelist.push_back("double"); 
                } else if (mat_var->data_type == 7) { typelist.push_back("float"); 
                } else { typelist.push_back("unsupported"); }

                // Store the variable name.
                varlist.push_back(mat_var->name);
                
                // Add one to the variable counter.
                nvars = nvars + 1;

                // Free the current variable.
                Mat_VarFree(mat_var);

                // Load the new variable.
                mat_var = Mat_VarReadNext(mat_file);

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
        matvar openvar ( std::string variable ) {
            
            // Initialize matvar.
            matvar mat_var;

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