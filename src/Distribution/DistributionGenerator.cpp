#include "DistributionGenerator.h"

void DistributionGenerator::generateSamplesFromDistributionFile(const std::string &distributionFilename, const std::string &outputDataFile,
                                                                unsigned int sampleCount)
{
    std::unique_ptr<Data> data(new Data());
    data->generateFromDistribution(distributionFilename, sampleCount);
    data->saveToFile(outputDataFile);
}

void DistributionGenerator::createNormalDistribution(const std::string &outputDistributionFile, double & mean, double & standardDeviation)
{
    std::unique_ptr<NormalDistribution> distribution(new NormalDistribution());
    distribution->generate(mean, standardDeviation, outputDistributionFile);
}

void DistributionGenerator::createLaplaceDistribution(const std::string &outputDistributionFile, double & mean, double & lambda)
{
    std::unique_ptr<LaplaceDistribution> distribution(new LaplaceDistribution());
    distribution->generate(mean, lambda, outputDistributionFile);
}

void DistributionGenerator::createUniformDistribution(const std::string &outputDistributionFile)
{
    std::unique_ptr<UniformDistribution> distribution(new UniformDistribution());
    distribution->generate(outputDistributionFile);
}
