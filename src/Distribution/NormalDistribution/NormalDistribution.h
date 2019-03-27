#pragma once

#include <string>
#include <climits>
#include <vector>
#include <math.h>
#include <fstream>

class NormalDistribution {
    public:
        void generate(unsigned char mean, std::string path);
};