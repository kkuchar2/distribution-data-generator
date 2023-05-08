#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <cxxopts.hpp>
#include "../Distribution/DistributionGenerator.h"

class ArgumentProcessor
{
    public:
        static void checkOptionConflict(const cxxopts::ParseResult &args, const std::string &opt1, const std::string &opt2)
        {
            if (args.count(opt1) && !args[opt1].has_default() && args.count(opt2) && !args[opt2].has_default())
            {
                throw std::logic_error("Conflicting options '" + opt1 + "' and '" + opt2 + "'.");
            }
        }

        static void checkRequiredOption(const cxxopts::ParseResult &args, const std::string &for_what,
                                        const std::string &required_option)
        {
            if (args.count(for_what) && !args[for_what].has_default())
            {
                if (args.count(required_option) == 0 || args[required_option].has_default())
                {
                    throw std::logic_error("Option '" + for_what + "' requires option '" + required_option + "'.");
                }
            }
        }

        static void assertOptionExists(const cxxopts::ParseResult &args, const std::string &required_param)
        {
            if (args.count(required_param) == 0 || args[required_param].has_default())
            {
                throw std::logic_error("Parameter '" + required_param + "' is needed.");
            }
        }

        template<typename T>
        static T get_value(const cxxopts::ParseResult &args, const std::string &key)
        {
            return args[key].as<T>();
        }

        static void process(int argc, char *argv[])
        {
            cxxopts::Options options("Allowed options");
            options.set_width(150);

            options.add_options("Help")
                    ("h,help", "Show help");

            options.add_options("Modes")
                    ("g,generator", "Generation of file containing 256 numbers representing distribution", cxxopts::value<bool>())
                    ("d,data", "Generate samples from distribution file", cxxopts::value<bool>());

            options.add_options("Data Generation")
                    ("i,input_file", "Input distribution file", cxxopts::value<std::string>())
                    ("c,sample_count", "Number of samples to generate", cxxopts::value<int>());

            options.add_options("Output")
                    ("o,output_file", "Output file", cxxopts::value<std::string>());

            options.add_options("Distribution Generation")
                    ("t,distribution", "Distribution type [ uniform | normal | laplace ]", cxxopts::value<std::string>())
                    ("m,mean", "Mean for normal | laplace distribution [double]", cxxopts::value<double>())
                    ("s,standard_deviation", "Standard deviation for normal distribution", cxxopts::value<double>())
                    ("l,lambda", "Scale parameter for Laplace distribution", cxxopts::value<double>());

            auto args = options.parse(argc, argv);

            if (args.count("help"))
            {
                std::cout << std::endl;
                std::cout << "Usage: distribution-generator [options]\n";
                std::cout << std::endl;
                std::cout << options.help();
                return;
            }

            // Make sure 'generator' and 'data' are not provided together
            checkOptionConflict(args, "data", "distribution");

            if (args.count("generator"))
            {
                // Make sure 'generator' has 'distribution' and 'output_file' provided by the user
                checkRequiredOption(args, "generator", "output_file");
                checkRequiredOption(args, "generator", "distribution");

                auto outputFile = get_value<std::string>(args, "output_file");
                auto distributionType = get_value<std::string>(args, "distribution");

                if (distributionType == "laplace")
                {
                    // Laplace distribution requires 'mean' and 'lambda' parameters
                    assertOptionExists(args, "mean");
                    assertOptionExists(args, "lambda");
                    auto mean = get_value<double>(args, "mean");
                    auto lambda = get_value<double>(args, "lambda");
                    DistributionGenerator::createLaplaceDistribution(outputFile, mean, lambda);
                }
                else if (distributionType == "normal")
                {
                    // Normal distribution requires 'mean' and 'standard_deviation' parameters
                    assertOptionExists(args, "mean");
                    assertOptionExists(args, "standard_deviation");
                    auto mean = get_value<double>(args, "mean");
                    auto standardDeviation = get_value<double>(args, "standard_deviation");

                    // make sure there is no 'lambda' parameter
                    if (args.count("lambda") && !args["lambda"].has_default())
                    {
                        throw std::logic_error("Normal distribution does not require 'lambda' parameter.");
                    }

                    DistributionGenerator::createNormalDistribution(outputFile, mean, standardDeviation);
                }
                else if (distributionType == "uniform")
                {
                    DistributionGenerator::createUniformDistribution(outputFile);
                }
                else
                {
                    throw std::logic_error("Unknown distribution type: " + distributionType +
                                           ". Please use one of [ uniform | normal | laplace ]");
                }
            }
            else if (args.count("data"))
            {
                // Make sure 'data' has 'input_file', 'output_file' and 'sample_count' provided by the user
                checkRequiredOption(args, "data", "input_file");
                checkRequiredOption(args, "data", "output_file");
                checkRequiredOption(args, "data", "sample_count");

                auto inputFile = get_value<std::string>(args, "input_file");
                auto outputFile = get_value<std::string>(args, "output_file");
                auto sampleCount = get_value<int>(args, "sample_count");

                DistributionGenerator::generateSamplesFromDistributionFile(inputFile, outputFile, sampleCount);
            }
            else
            {
                std::cout << std::endl;
                std::cout << "Usage: distribution-generator [options]\n";
                std::cout << std::endl;
                std::cout << options.help();
                return;
            }
        }
};