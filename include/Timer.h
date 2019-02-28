class timer {
    public:
        // Data
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        
        // Methods
        // Start/reset the timer.
        void tic (  ) {
            start = std::chrono::high_resolution_clock::now();
        }

        // Stop the timer and print the result.
        void toc (  ) {

            std::chrono::duration<double> elapsed_time = std::chrono::high_resolution_clock::now() - start;
            
            std::cout << "elapsed time: " << elapsed_time.count() << std::endl;

        }

        // Stop the timer and save the result.
        double toc ( std::string save ) {

            std::chrono::duration<double> elapsed_time = std::chrono::high_resolution_clock::now() - start;
            
            return (double) elapsed_time.count();

        }

}; timer _timer;

// Start/reset the timer.
void tic () { _timer.tic(); }

// Stop the timer and print the result.
void toc () { _timer.toc(); }

// Stop the timer and save the result.
double toc_s () { double result = _timer.toc("save"); return result; }