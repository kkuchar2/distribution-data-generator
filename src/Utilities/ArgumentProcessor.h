#pragma once

#include "../Distribution/DistributionGenerator.h"

/*
##########################################################################################
distribution [distribution_type] [mean (optional)] where distribution_type = uniform | normal | laplace
data [distribution_file_path] [output_path] [number_of_samples]

example: 'ddgenerator -distribution -
############################################################################################
*/

class ArgumentProcessor {
    public:

        static void process_data_generator(int &parameterCount, char * argv[]) {
            if (parameterCount < 5) {
                throw std::runtime_error("Wrong number of parameters");
            }
            DistributionGenerator::generateDataFromDistributionFile(argv[3], argv[4], argv[5]);
        }

        static void process_distribution_generator(int &parameterCount, char *argv[]) {
            std::string mode = argv[2];

            if (mode == "distribution") {

                if (parameterCount < 4) {
                    throw std::runtime_error("Wrong number of parameters");
                }

                // Get distribution type and output distribution file path
                std::string distributionType = argv[3];

                if (distributionType == "uniform") {
                    DistributionGenerator::generateUniformDistribution(argv[4]);
                }
                else if (distributionType == "normal") {
                    DistributionGenerator::generateNormalDistribution(argv[4], argv, parameterCount);
                }
                else if (distributionType == "laplace") {
                    DistributionGenerator::generateLaplaceDistribution(argv[4], argv, parameterCount);
                }
                else {
                    throw std::runtime_error("Wrong distribution type");
                }
            }
        }

        static void process(int &argc, char *argv[]) {
            auto parameterCount = argc - 1;

            if (parameterCount < 2) {
                throw std::runtime_error("Wrong number of parameters");
            }

            std::string firstParameter = argv[1];

            if (firstParameter == "generator") {
                ArgumentProcessor::process_distribution_generator(parameterCount, argv);
            }
            else if (firstParameter == "data") {
                ArgumentProcessor::process_data_generator(parameterCount, argv);
            }
            else {
                throw std::runtime_error("Wrong first parameter");
            }
        }
};