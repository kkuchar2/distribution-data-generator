#include "UniformDistribution.h"

void UniformDistribution::generate(const std::string &outputDistributionFile)
{
    std::vector<double> probabilities(UCHAR_MAX);

    double probability = 1.0 / static_cast<double>(UCHAR_MAX - 0);

    for (int x = 0; x < UCHAR_MAX; x++)
    {
        probabilities[static_cast<unsigned char>(x)] = probability;
        std::cout << "[" << x << "] = " << probability << std::endl;
    }

    writeToFile(outputDistributionFile, probabilities);
}