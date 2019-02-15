#include <matio.h>
#include <string>
#include <iostream>
#include <list>

class matfile_load {
    public:

        // Data
        std::string path;                   // Path to MAT file to load.
        std::string name;                   // Name of MAT file to load.
        std::string full_name;              // path + name of MAT file to load.
        mat_t * mat_file;                   // MatIO stream of MAT file to load.
        int status;                         // Status of MatIO stream to load.
        std::list<std::string> varlist;     // List containing the variable names in MAT file to load.
        int nvars = 0;                      // Number of variables of MAT file to load.

        // Methods
        void getvarnames (  ) {

            // Declare variables.
            std::string matvarname;
            matvar_t * mat_var = Mat_VarReadNextInfo(mat_file);

            // Loop over the variables.
            while ( mat_var != NULL ) {

                // Temporary storage of variable name.
                matvarname = mat_var->name;

                // Add the variable name to varlist.
                varlist.push_back(matvarname);
                nvars = nvars + 1;

                // Free the current variable
                Mat_VarFree(mat_var);

                // Load the new variable.
                mat_var = Mat_VarReadNextInfo(mat_file);

            }

            // Reset the MatIO stream.
            Mat_Rewind(mat_file);

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
            if ( status == 1) {
                getvarnames();
            }

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
            if ( status == 1) {
                getvarnames();
            }

        }

        // Destructor
        ~matfile_load (  ) {

            // Close the MAT file stream.
            Mat_Close(mat_file);

        }

};

int main () {
    
    matfile_load matfile("matfile.mat");

    std::cout << matfile.nvars << std::endl;
    
    return 0;
    
}