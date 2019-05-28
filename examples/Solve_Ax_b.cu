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

    // year/month/day_hour:min:sec
    std::string time_str =  year+"-"+month+"-"+day+"_"+hour+":"+min+":"+sec;
    
    // Return the name of the output file. 
    return "log/"+name+"_"+time_str+".log";

}

// Create and open log file (overwrite).
std::ofstream create_log ( std::string name, std::string matfile,
                           std::string conffile, std::string backend ) {

    // Create 'log' directory.
    system("if [ ! -d \"log\" ]; then mkdir log; fi");

    // Output file.
    std::ofstream log;
    log.open(get_output_file_name(name));

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
    if ( std::regex_match(argv[0], std::regex("(./)(.*)")) ) {

        // Remove './' from input argument.
        std::string check = argv[0];
        check.erase(0,2);

    }

    // Return the result.
    return check;

}

int main ( int argc, char* argv[] ) {

    // Iput argument processing.
    std::string name = in_arg_check(argc,argv);
    if (name == "error") { return 0; }
    std::string matfile = argv[1], conffile = argv[2], backend = argv[3];
                
    // Log file.
    std::ofstream log = create_log(name, matfile, conffile, backend);
    log.close();
       
    // Open the MAT file.
    matfile_load mat_file_load(matfile);

    // Solve using the CPU.
    if ( backend == "CPU" ) {

        // Extract data to host memory.
        CPU_Sparse A(mat_file_load,"A");
        CPU_Dense  b(mat_file_load,"b");

        // Solve Ax=b (and time).
        tic();
        CPU_Dense x = A.solve(b,conffile);
        toc();

        // Calculate the residual.
        CPU_Dense b_x = A.mv(x);
        CPU_Dense res = b_x.add(b.scp(-1));

        // Print the result.
        std::cout << "2-norm of the residual is: " << sqrt(res.dot(res)) << std::endl;

    }
        
    // Solve using the GPU.
    if ( backend == "GPU" ) {
            
        // Extract data to device memory.
        GPU_Sparse A(mat_file_load,"A");
        GPU_Dense  b(mat_file_load,"b");

        // Solve Ax=b (and time).
        tic();
        GPU_Dense x = A.solve(b,conffile);
        toc();

        // Calculate the residual.
        GPU_Dense b_x = A.mv(x);
        GPU_Dense res = b_x.add(b.scp(-1));

        // Print the result.
        std::cout << "2-norm of the residual is: " << sqrt(res.dot(res)) << std::endl;

    }

    // Exit.
    return 0;

}