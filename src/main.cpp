#include "Utilities/ArgumentProcessor.h"
#include <boost/program_options.hpp>
#include "TreeNode.h"

int main(int argc, char * argv[]) {

    try {
        ArgumentProcessor::process(argc, argv);
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
        exit(0);
    }
}