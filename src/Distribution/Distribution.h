#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Distribution
{
    protected:
        void writeToFile(const std::string &outputDistributionFile, const std::vector<double> &probabilities);
};