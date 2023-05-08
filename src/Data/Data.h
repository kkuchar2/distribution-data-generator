#pragma once

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <random>
#include <sys/stat.h>

class Data
{
    protected:
        // Symbols stored in data
        std::vector<unsigned char> symbols;
    public:
        Data();

        // Check if file exists
        static int fileExists(const char *filename)
        {
            struct stat buffer{};
            return (stat(filename, &buffer) == 0);
        }

        // Initialize data with array
        void initWithArray(unsigned char *data, int size);

        // Generate data from distribution file
        void generateFromDistribution(const std::string &path, unsigned int size);

        // Save data to file
        void saveToFile(const std::string &path);

        // Read data from file
        void readFromFile(const std::string &path);

        // Compare two data objects
        bool compare(const std::unique_ptr<Data> &data);

        // Get symbols
        const std::vector<unsigned char> &getSymbols();

        // Get size
        size_t getSize();

        ~Data();
};
