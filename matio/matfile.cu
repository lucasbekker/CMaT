#include <matio.h>
#include <string>
#include <iostream>
#include <list>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

// Struct used in matfile_load.
struct matvar {

    matvar_t * variable;                    // MatIO variable.
    std::string type;                       // Double or Float.
    bool issparse = false;                  // True if MatIO variable is a sparse variable.
    mat_sparse_t * sparse;                  // Only contains data if "matvar.issparse=true".

};

// Struct used in matfile_load.
struct matsparse {

    thrust::host_vector<double> hvd;        // CPU double sparse values vector.
    thrust::host_vector<float> hvf;         // CPU float sparse values vector.
    thrust::host_vector<int> hipb;          // CPU sparse begin pointer list vector.
    thrust::host_vector<int> hipe;          // CPU sparse end pointer list vector.
    thrust::host_vector<int> hj;            // CPU sparse index list vector.
    thrust::device_vector<double> dvd;      // GPU double sparse values vector.
    thrust::device_vector<float> dvf;       // GPU float sparse values vector.
    thrust::device_vector<int> dip;         // GPU sparse pointer list vector.
    thrust::device_vector<int> dj;          // GPU sparse index list vector.

};

// Class definition of a MAT file from which to load variables.
class matfile_load {
    public:

        // Data
        std::string path;                   // Path to MAT file to load.
        std::string name;                   // Name of MAT file to load.
        std::string full_name;              // path + name of MAT file to load.
        std::list<std::string> varlist;     // List containing the variable names in MAT file to load.

        mat_t * mat_file;                   // MatIO stream of MAT file to load.
        int status;                         // Status of MatIO stream to load.
        int nvars = 0;                      // Number of variables of MAT file to load.

        // Methods
        // Fill varlist with the names of the variables in the Mat file.
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

        // Print the content of varlist. 
        void printvarnames (  ) {

            // Loop over the elements in varlist.
            for ( std::list<std::string>::iterator it = varlist.begin();
                it != varlist.end(); ++it ) {
                std::cout << *it << std::endl;
            }

        }

        // Open a variable in the MAT file.
        matvar openvar ( std::string variable ) {
            
            // Initialize matvar.
            matvar mat_variable;

            // Open variable in .mat file.
            mat_variable.variable = Mat_VarRead(mat_file,variable.c_str());

            // Check succesfull opening of variable in .mat file.
            if (mat_variable.variable == NULL) {
                std::cout << "Variable: '" << variable << "' not found." << std::endl; 
            } else {

                // Check if the variable is sparse.
                if (mat_variable.variable->class_type == 5) {
                    mat_variable.issparse = true;
                    mat_variable.sparse = (mat_sparse_t *) mat_variable.variable->data;
                }

                // Check if the variable is of type double or float.
                if (mat_variable.variable->data_type == 9) { mat_variable.type = "double"; }
                if (mat_variable.variable->data_type == 7) { mat_variable.type = "float"; }
                
            }

            return mat_variable;

        }

        /*
        matsparse spd_cpu ( std::string variable ) {  }

        matsparse spf_cpu ( std::string variable ) {  }

        thrust::host_vector<double> dd_cpu ( std::string variable ) {  }

        thrust::host_vector<float> df_cpu ( std::string variable ) {  }

        matsparse spd_gpu ( std::string variable ) {  }

        matsparse spf_gpu ( std::string variable ) {  }

        thrust::device_vector<double> dd_gpu ( std::string variable ) {  }

        thrust::device_vector<float> df_gpu ( std::string variable ) {  }
        */
 
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

    matvar mat_variable = matfile.openvar("b");

    /*mat_sparse_t * mat_sparse = (mat_sparse_t * ) mat_variable.variable->data;

    double * mat_sparse_v = (double *) mat_sparse->data;

    std::cout << mat_sparse->ir[3] << std::endl;
    std::cout << mat_sparse_v[3] << std::endl;*/

    double * mat_variable_data = (double *) mat_variable.variable->data;

    std::cout << mat_variable_data[1] << std::endl;
    
    return 0;
    
}