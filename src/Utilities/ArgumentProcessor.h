#pragma once

#include <boost/program_options.hpp>
#include "../Distribution/DistributionGenerator.h"

using namespace boost;
namespace po = boost::program_options;

class ArgumentProcessor {

    public:

        static void conflicting_options(const po::variables_map & vm, const char * opt1, const char * opt2) {
            if (vm.count(opt1) && !vm[opt1].defaulted() && vm.count(opt2) && !vm[opt2].defaulted()) {
                throw std::logic_error(std::string("Conflicting options '") + opt1 + "' and '" + opt2 + "'.");
            }
        }

        static void
        option_dependency(const po::variables_map & vm, const char * for_what, const char * required_option) {
            if (vm.count(for_what) && !vm[for_what].defaulted()) {
                if (vm.count(required_option) == 0 || vm[required_option].defaulted()) {
                    throw std::logic_error(
                            std::string("Option '") + for_what + "' requires option '" + required_option + "'.");
                }
            }
        }

        static void param_presence(const po::variables_map & vm, const char * required_param) {
            if (vm.count(required_param) == 0 || vm[required_param].defaulted()) {
                throw std::logic_error(
                        std::string("Parameter '") + required_param + "' is needed.");
            }
        }

        static std::string get_string(const po::variables_map & vm, const std::string & key) {
            return vm[key].as<std::string>();
        }

        static int get_int(const po::variables_map & vm, const std::string & key) {
            return vm[key].as<int>();
        }

        static void process(int & argc, char * argv[]) {

            po::options_description optionsDescription("Allowed options");

            optionsDescription.add_options()

                    ("help,h", "show help")
                    ("generator,g", "generate distribution file.")
                    ("distribution,t", po::value<std::string>(), "distribution type [ uniform | normal | laplace ]")
                    ("data,d", "generate data from distribution file")
                    ("mean,m", po::value<int>(), "Mean for normal | laplace distribution")
                    ("input_file,i", po::value<std::string>(), "Input distribution file")
                    ("output_file,o", po::value<std::string>(), "Output file for distribution | data")
                    ("sample_count,c", po::value<int>(), "Number of samples to generate")

                    ;

            po::variables_map vm;
            po::store(po::command_line_parser(argc, argv).options(optionsDescription).run(), vm);
            po::notify(vm);

            if (vm.count("help")) {
                std::cout << std::endl;
                std::cout << "Usage: ddgenerator [options]\n";
                std::cout << std::endl;
                std::cout << optionsDescription;
                return;
            }

            option_dependency(vm, "generator", "output_file");
            option_dependency(vm, "generator", "distribution");
            conflicting_options(vm, "data", "distribution");

            if (vm.count("generator")) {

                option_dependency(vm, "generator", "output_file");

                auto outputFile = get_string(vm, "output_file");
                auto distributionType = get_string(vm, "distribution");

                if (distributionType == "laplace") {
                    param_presence(vm, "mean");
                    LaplaceDistribution::generate(get_int(vm, "mean"), outputFile);
                }
                else if (distributionType == "normal") {
                    param_presence(vm, "mean");
                    NormalDistribution::generate(get_int(vm, "mean"), outputFile);
                }
                else if (distributionType == "uniform") {
                    UniformDistribution::generate(outputFile);
                }
            }
            else if (vm.count("data")) {
                option_dependency(vm, "data", "input_file");
                option_dependency(vm, "data", "output_file");
                option_dependency(vm, "data", "sample_count");

                DistributionGenerator::generateDataFromDistributionFile(
                        get_string(vm, "input_file"),
                        get_string(vm, "output_file"),
                        get_int(vm, "sample_count")
                );
            }
        }
};