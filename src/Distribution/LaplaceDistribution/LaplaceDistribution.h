#pragma once

#include <string>
#include <climits>
#include <vector>
#include <cmath>
#include <fstream>

class LaplaceDistribution {
    public:
        void generate(unsigned char mean, std::string path);
};