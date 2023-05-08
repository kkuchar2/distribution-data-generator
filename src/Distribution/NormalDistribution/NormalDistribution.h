#pragma once

#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include "../Distribution.h"

class NormalDistribution : protected Distribution
{
    public:
        void generate(double & mean, double & standardDeviation, const std::string &outputDistributionFile);
};