#pragma once

#include <string>
#include <climits>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include "../Distribution.h"

class LaplaceDistribution : protected Distribution
{
    public:
        void generate(double & mean, double & lambda, const std::string &outputDistributionFile);
};