#include "NormalDistribution.h"

void NormalDistribution::generate(double & mean, double & standardDeviation, const std::string &outputDistributionFile)
{
    // Average half width of distribution
    double average_bound_width = ((mean - 0) + (UCHAR_MAX - mean)) / 2;

    // Standard deviation: 3x stddev rule = ~99.7% of distribution lies within range
    double const standard_deviation = average_bound_width / 3;

    std::vector<double> probabilities(UCHAR_MAX + 1);

    for (unsigned int x = 0; x <= UCHAR_MAX; ++x)
    {
        auto probability = (1.0 / (sqrt(2.0 * M_PI) * standard_deviation))
                           * exp(-pow(x - mean, 2) / (2 * pow(standard_deviation, 2)));
        probabilities[x] = probability;
        std::cout << "[" << x << "] = " << probability << std::endl;
    }

    writeToFile(outputDistributionFile, probabilities);
}