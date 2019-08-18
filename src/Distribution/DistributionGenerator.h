#pragma once

#include <string>
#include <memory>

#include "UniformDistribution/UniformDistribution.h"
#include "NormalDistribution/NormalDistribution.h"
#include "LaplaceDistribution/LaplaceDistribution.h"
#include "../Data/Data.h"

class DistributionGenerator {

    public:

        static void generateNormalDistribution(const char * outputDistributionFile, char * argv[], int & numberOfParameters) {
            // Default mean
            if (numberOfParameters == 4) {
                std::unique_ptr<NormalDistribution> distribution(new NormalDistribution());
                distribution->generate(128, outputDistributionFile);
            }
            // User defined mean
            else if (numberOfParameters == 5) {
                unsigned char mean = static_cast<unsigned char>(std::stoi(argv[5]));
                std::unique_ptr<NormalDistribution> distribution(new NormalDistribution());
                distribution->generate(mean, outputDistributionFile);
            }
        }

        static void generateLaplaceDistribution(const char * outputDistributionFile, char * argv[], int & numberOfParameters) {
            std::unique_ptr<LaplaceDistribution> distribution(new LaplaceDistribution());

            if (numberOfParameters == 4) {
                // Default mean
                distribution->generate(128, outputDistributionFile);
            }
            else if (numberOfParameters == 5) {
                // User defined mean
                unsigned char mean = static_cast<unsigned char>(std::stoi(argv[5]));
                distribution->generate(mean, outputDistributionFile);
            }
        }

        static void generateDataFromDistributionFile(const std::string & distributionFilename, const std::string & outputDataFile, unsigned int sampleCount) {
            std::unique_ptr<Data> data(new Data());
            data->generateFromDistribution(distributionFilename, sampleCount);
            data->saveToFile(outputDataFile);
        }
};
