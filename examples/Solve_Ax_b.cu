#include "../include/CMaT.h"
#include <fstream>
#include <ctime>
#include <regex>
#include <stdlib.h>

// Provide filename for log file.
std::string get_output_file_name ( std::string name ) {
    
    // Time and date information.
    std::time_t now = std::time(0);
    tm * ltm = localtime(&now);

    // Date string.
    std::string year  = std::to_string(1900 + ltm->tm_year);
    std::string month = std::to_string(1 + ltm->tm_mon);
    std::string day   = std::to_string(ltm->tm_mday);

    // Time string.
    std::string hour = std::to_string(ltm->tm_hour);
    std::string min  = std::to_string(ltm->tm_min);
    std::string sec  = std::to_string(ltm->tm_sec);

    // year-month-day_hour:min:sec
    std::string time_str =  year+"-"+month+"-"+day+"_"+hour+":"+min+":"+sec;
    
    // Return the name of the output file. 
    return "log/"+name+"_"+time_str+".log";

}

// Create and open log file (overwrite).
std::ofstream create_log ( std::string name, std::string matfile, std::string conffile,
                           std::string backend, std::string & filename ) {

    // Create 'log' directory.
    system("if [ ! -d \"log\" ]; then mkdir log; fi");

    // Output file.
    std::ofstream log;
    filename = get_output_file_name(name);
    log.open(filename);

    // Input parameters
    log << name << " " << matfile << " " << conffile 
        << " " << backend << std::endl << std::endl;

    // Return the log file stream.
    return log;

}

// Input argument processing.
std::string in_arg_check ( int argc, char* argv[] ) {

    // Initialize output.
    std::string check = argv[3];

    if ( argc != 4 ) {

        // Tell the user how to run the program.
        std::cout << "Usage: " << argv[0] 
                  << " MAT_file config_file GPU/CPU" 
                  << std::endl;

        // Error.
        return check = "error";
                    
    }

    // Backend check.
    if ( not((check == "GPU")||(check == "CPU")) ) {

        // Message to user.
        std::cout << "Current backend: " << argv[3] << std::endl;
        std::cout << "Backend should be: 'GPU' or 'CPU'" << std::endl;

        // Error.
        return check = "error";

    }

    // Manipulate the first input argument.
    check = argv[0];

    // Remove './' from input argument.
    if ( std::regex_match(argv[0], std::regex("(./)(.*)")) ) {

        check.erase(0,2);

    }

    // Return the result.
    return check;

}

// Store timings, num_iter and norm of residual in a matlab vector.
void create_mat ( double t1, double t2, double t3,
                  double r_norm, std::string filename ) {

    // Initialize the result vector.
    CPU_Dense result(5,1);

    // Fill the result vector.
    result.Values[0] = t1;
    result.Values[1] = t2;
    result.Values[2] = t3;
    result.Values[3] = r_norm;
    result.Values[4] = (double) num_iter;

    // Create './MAT_FILES/results' directory.
    system("if [ ! -d \"MAT_FILES\" ]; then mkdir MAT_FILES; fi");
    system("if [ ! -d \"MAT_FILES/results\" ]; then mkdir MAT_FILES/results; fi");

    // Construct filename.
    filename.pop_back(); filename.pop_back();
    filename.pop_back(); filename.pop_back();
    filename.erase(0,4);

    // Open MAT file for saving.
    matfile_save mat_file_save("./MAT_FILES/results",filename + ".mat");
    
    // Store the result vector in the MAT file.
    result.save(mat_file_save,"result");    

}

int main ( int argc, char* argv[] ) {

    // Iput argument processing.
    std::string name = in_arg_check(argc,argv);
    if (name == "error") { return 0; }
    std::string matfile = argv[1], conffile = argv[2], backend = argv[3];
                
    // Open log file.
    std::string filename;
    std::ofstream log = create_log(name, matfile, conffile, backend, filename);
       
    // Open the MAT file.
    matfile_load mat_file_load(matfile);

    // Timings and residual.
    double t1, t2, t3, r_norm;

    // Solve using the CPU.
    if ( backend == "CPU" ) {

        // Extract data to host memory (and time).
        tic();
        CPU_Sparse A(mat_file_load,"A");
        CPU_Dense  b(mat_file_load,"b");
        t1 = toc_s();
        log << "Loading and transposing took: " << t1 << " seconds" << std::endl;

        // Solve Ax=b (and time).
        tic();
        CPU_Dense x = A.solve(b,conffile);
        t2 = toc_s();
        log << "Solving Ax=b took: " << t2 << " seconds" << std::endl;

        // Calculate the residual.
        tic();
        CPU_Dense b_x = A.mv(x);
        CPU_Dense res = b_x.add(b.scp(-1));
        r_norm = sqrt(res.dot(res));
        t3 = toc_s();
        log << "Getting the residual norm took: " << t3 << " seconds" << std::endl;

        // Print the result.
        log << std::endl << "2-norm of the residual is: " << r_norm << std::endl;
        log << "Number of iterations: " << num_iter << std::endl;

    }
        
    // Solve using the GPU.
    if ( backend == "GPU" ) {
            
        tic();
        GPU_Sparse A(mat_file_load,"A");
        GPU_Dense  b(mat_file_load,"b");
        t1 = toc_s();
        log << "Loading and transposing took: " << t1 << " seconds" << std::endl;

        // Solve Ax=b (and time).
        tic();
        GPU_Dense x = A.solve(b,conffile);
        t2 = toc_s();
        log << "Solving Ax=b took: " << t2 << " seconds" << std::endl;

        // Calculate the residual.
        tic();
        GPU_Dense b_x = A.mv(x);
        GPU_Dense res = b_x.add(b.scp(-1));
        r_norm = sqrt(res.dot(res));
        t3 = toc_s();
        log << "Getting the residual norm took: " << t3 << " seconds" << std::endl;

        // Print the result.
        log << std::endl << "2-norm of the residual is: " << r_norm << std::endl;
        log << "Number of iterations: " << num_iter << std::endl;

    }

    create_mat(t1, t2, t3, r_norm, filename);

    // Close log file.
    log.close();

    // Exit.
    return 0;

}