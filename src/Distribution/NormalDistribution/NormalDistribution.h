#pragma once

#include <string>
#include <climits>
#include <vector>
#include <cmath>
#include <fstream>

class NormalDistribution {
    public:
        static void generate(const int & mean, const std::string & path);
};