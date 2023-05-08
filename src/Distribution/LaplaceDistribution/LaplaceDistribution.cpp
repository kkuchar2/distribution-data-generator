#include "LaplaceDistribution.h"

void LaplaceDistribution::generate(double & mean, double & lambda, const std::string &outputDistributionFile)
{
    std::cout << "Generating Laplace distribution" << std::endl;

    std::vector<double> probabilities(UCHAR_MAX + 1);

    for (unsigned int x = 0; x <= UCHAR_MAX; ++x)
    {
        double probability = 1.0 / (2.0 * lambda) * exp(-std::abs(static_cast<double>(x) - mean) / lambda);
        probabilities[x] = probability;
        std::cout << "[" << x << "] = " << probability << std::endl;
    }

    writeToFile(outputDistributionFile, probabilities);
}
