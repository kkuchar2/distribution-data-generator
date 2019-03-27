#include "Utilities/ArgumentProcessor.h"

/*
##########################################################################################
generator distribution [distribution_type] [mean (optional)] where distribution_type = uniform | normal | laplace
generator data [distribution_file_path] [output_path] [number_of_samples]
############################################################################################
*/
int main(int argc, char* argv[]) {
    try {
        ArgumentProcessor::process(argc, argv);
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
        exit(0);
    }
}