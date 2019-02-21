// STD libs.
#include <iostream>
#include <assert.h>
#include <string>
#include <list>

// Included for .mat file support.
#include <matio.h>

// Class definition of a MAT file in which to save variables.
class matfile_save {
    public:
        // Data
        std::string filename;                   // Name of MAT file to save.
        std::list<std::string> varlist;         // List containing the variable names in MAT file to save.
        mat_t * mat_file;                       // MatIO stream of MAT file to save.
        int status;                             // Status of MatIO stream to save.

        // Methods
        // Save a Dense double array.
        void ddsave ( std::string varname, double * datap, int m, int n ) {

            // Check the variable name.
            varcheck(varname);
            
            // Store dimension data in the required format.
            size_t dims[2]; dims[0] = (size_t) m; dims[1] = (size_t) n;

            // Create the MAT file variable.
            matvar_t * mat_var = Mat_VarCreate(varname.c_str(),MAT_C_DOUBLE,
                                               MAT_T_DOUBLE,2,dims,datap,0);

            // Check for errors, add to variable list and save the result.                                   
            if ( mat_var == NULL ) {
                std::cout << "Error creating variable \"" << varname << "\"" 
                          << std::endl;
                status = 0;
            } else if ( status == 1 ) { 
                varlist.push_back(varname);
                Mat_VarWrite(mat_file,mat_var,MAT_COMPRESSION_NONE);
                Mat_VarFree(mat_var); 
            }

        }

        // Save a Dense float array.
        void dfsave ( std::string varname, float * datap, int m, int n ) {

            // Check the variable name.
            varcheck(varname);

            // Store dimension data in the required format.
            size_t dims[2]; dims[0] = (size_t) m; dims[1] = (size_t) n;

            // Create the MAT file variable.
            matvar_t * mat_var = Mat_VarCreate(varname.c_str(),MAT_C_SINGLE,
                                               MAT_T_SINGLE,2,dims,datap,0);

            // Check for errors, add to variable list and save the result.
            if ( mat_var == NULL ) {
                std::cout << "Error creating variable \"" << varname << "\"" 
                          << std::endl;
                status = 0;
            } else if ( status == 1 ) { 
                varlist.push_back(varname);
                Mat_VarWrite(mat_file,mat_var,MAT_COMPRESSION_NONE);
                Mat_VarFree(mat_var); 
            }

        }

        // Save a Sparse array.
        void spsave ( std::string varname, mat_sparse_t * datap, enum matio_types data_type, int m, int n ) {

            // Check the variable name.
            varcheck(varname);

            // Store dimension data in the required format.
            size_t dims[2]; dims[0] = (size_t) m; dims[1] = (size_t) n;

            // Create the MAT file variable.
            matvar_t * mat_var = Mat_VarCreate(varname.c_str(),MAT_C_SPARSE,data_type,2,dims,datap,0);

            // Check for errors, add to variable list and save the result.
            if ( mat_var == NULL ) {
                std::cout << "Error creating variable \"" << varname << "\"" 
                          << std::endl;
                status = 0;
            } else if ( status == 1 ) { 
                varlist.push_back(varname);
                Mat_VarWrite(mat_file,mat_var,MAT_COMPRESSION_NONE);
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

        // Constructor
        matfile_save ( std::string NAME ) {

            // Store filename.
            filename = NAME;

            // Create MAT file and check status.
            mat_file = Mat_CreateVer(filename.c_str(),NULL,MAT_FT_DEFAULT);
            if ( NULL == mat_file ) {
                std::cout << "Error creating MAT file \"" << filename << "\"" << std::endl;
                status = 0;
            } else { status = 1; }

        }

        // Destructor
        ~matfile_save (  ) {

            // Close the MAT file.
            Mat_Close(mat_file);

        }

};