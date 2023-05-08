#pragma once

#include <string>
#include <memory>

#include "UniformDistribution/UniformDistribution.h"
#include "NormalDistribution/NormalDistribution.h"
#include "LaplaceDistribution/LaplaceDistribution.h"
#include "../Data/Data.h"

class DistributionGenerator
{

    public:
        static void createNormalDistribution(const std::string &outputDistributionFile, double & mean, double & standardDeviation);

        static void createLaplaceDistribution(const std::string &outputDistributionFile, double & mean, double & lambda);

        static void createUniformDistribution(const std::string &outputDistributionFile);

        static void
        generateSamplesFromDistributionFile(const std::string &distributionFilename, const std::string &outputDataFile, unsigned int sampleCount);
};


