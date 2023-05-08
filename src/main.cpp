#include "Utilities/ArgumentProcessor.h"

int main(int argc, char * argv[]) {

    try {
        ArgumentProcessor::process(argc, argv);
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
        exit(0);
    }
}