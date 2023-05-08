#include "Distribution.h"

void Distribution::writeToFile(const std::string &outputDistributionFile,
                               const std::vector<double> &probabilities)
{
    double sumOfProbabilities = 0.0;

    for (double probability: probabilities)
    {
        sumOfProbabilities += probability;
    }

    std::ofstream out(outputDistributionFile);

    for (size_t i = 0; i < probabilities.size(); i++)
    {
        out << static_cast<int>(i) << " " << probabilities[i] / sumOfProbabilities << std::endl;
    }

    out.close();

    std::cout << "Distribution written to " << outputDistributionFile << std::endl;
}
