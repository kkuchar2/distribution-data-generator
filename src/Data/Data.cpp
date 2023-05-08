
#include "Data.h"

Data::Data() = default;

void Data::initWithArray(unsigned char *data, int size)
{
    symbols.assign(data, data + size);
}

void Data::saveToFile(const std::string &path)
{
    std::ofstream out(path, std::ofstream::binary);

    // Fill output file with chars generated from symbols
    for (unsigned char &symbol: symbols)
    {
        out.write((char *) (&symbol), sizeof(symbol));
    }

    out.close();
}

void Data::readFromFile(const std::string &path)
{
    std::ifstream f(path, std::ios::binary | std::ios::in);

    char c;
    while (f.get(c))
    {
        symbols.push_back(static_cast<unsigned char>(c));
    }

    f.close();
}

void Data::generateFromDistribution(const std::string &path, unsigned int size)
{

    // Check if file exists
    if (!fileExists(path.c_str()))
    {
        throw std::runtime_error("File does not exist");
    }

    // Read distribution weights from file
    std::ifstream infile(path);

    // Vector for distribution weights
    std::vector<double> weights;

    // Read distribution weights
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);

        int number;
        double probability;

        if (!(iss >> number >> probability))
        {
            std::cout << "ERROR reading distribution!" << std::endl;
            break;
        }

        weights.push_back(probability);
    }

    // Random seed
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    // Generator from seed
    std::mt19937 generator(static_cast<unsigned int>(seed));

    // Create discrete distribution and feed it with distribution weights
    std::discrete_distribution<int> distribution(weights.begin(), weights.end());

    // Create unsigned char samples
    for (auto i = 0; i < size; i++)
    {
        symbols.push_back(static_cast<unsigned char>(distribution(generator)));
    }
}

bool Data::compare(const std::unique_ptr<Data> &data)
{
    bool identical = true;

    // Check size
    if (this->getSize() != data->getSize())
    {
        throw std::runtime_error("Data size not equal");
    }

    auto size = this->getSize();

    const std::vector<unsigned char> &otherSymbols = data->getSymbols();

    std::cout << "Comparing data..." << std::endl << std::endl;

    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] First data: " << static_cast<int>(symbols[i]) << " Second data: " << static_cast<int>(otherSymbols[i])
                  << std::endl;
        if (symbols[i] != otherSymbols[i])
        {
            identical = false;
            break;
        }
    }

    return identical;;
}

const std::vector<unsigned char> &Data::getSymbols()
{
    return symbols;
}

size_t Data::getSize()
{
    return symbols.size();
}

Data::~Data() = default;