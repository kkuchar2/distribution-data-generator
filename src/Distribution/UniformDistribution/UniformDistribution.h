#pragma once

#include <string>
#include <climits>
#include <iostream>
#include <fstream>
#include "../Distribution.h"

class UniformDistribution : protected Distribution
{
    public:
        void generate(const std::string &outputDistributionFile);
};