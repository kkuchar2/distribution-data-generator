[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/kkuchar2/distribution-data-generator">
    	🌀
  </a>

  <h3 align="center">distribution-data-generator</h3>

  <p align="center">
    Implementation of distribution based random data generation in C++
    <br />
    <br />
    <a href="https://github.com/kkuchar2/distribution-data-generator/issues">Report Bug</a>
        ·
    <a href="https://github.com/kkuchar2/distribution-data-generator/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
* [Usage](#usage)
* [Examples](#examples)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project

This project provides a simple command-line tool for generating distribution files and data files based on those distributions. With this tool, you can easily generate files containing distribution data for Laplace, normal, or uniform distributions, and generate data samples from existing distribution files.

To generate a distribution file, simply specify the distribution type (uniform, normal, or Laplace), mean (for normal and Laplace distributions), and any other necessary parameters (such as standard deviation for the normal distribution or scale parameter for the Laplace distribution). The tool will then generate a file containing 256 numbers representing the specified distribution.

To generate data samples from a distribution file, specify the input distribution file and the number of samples to generate. The tool will generate a file containing the specified number of samples, drawn from the distribution specified in the input file.

<!-- GETTING STARTED -->
## Getting Started

Clone the repo

```sh
git clone https://github.com/kkuchar2/distribution-data-generator
```

Make sure you've installed cxxopts library

```sh
sudo apt-get install libcxxopts-dev
```

Build executable
```sh
cd distribution-data-generator
mkdir build
cd build
cmake ..
make
```

## Usage

```sh
./distribution-generator [OPTIONS]

-h, --help                      Show help
-g, --generator                 Generate a file with distribution data
-d, --data                      Generate data samples using distribution file
-i, --input_file=INPUT          Input distribution file
-c, --sample_count=COUNT        Number of samples to generate
-o, --output_file=OUTPUT        Output file
-t, --distribution=TYPE         Distribution type [uniform|normal|laplace]
-m, --mean=MEAN                 Mean for normal or laplace distribution [double]
-s, --standard_deviation=SD     Standard deviation for normal distribution
-l, --lambda=SCALE              Scale parameter for Laplace distribution
```
## Examples
```sh
Generate distribution file:
./distribution-generator -g -o distribution.txt -t normal -m 0 -s 1
./distribution-generator -g -o distribution.txt -t laplace -m 0 -l 1
./distribution-generator -g -o distribution.txt -t uniform

Generate data samples:
./distribution-generator -d -i distribution.txt -o data.txt -c 1000
```

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/kkuchar2/distribution-data-generator.svg?style=flat-square
[contributors-url]: https://github.com/kkuchar2/distribution-data-generator/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/kkuchar2/distribution-data-generator.svg?style=flat-square
[forks-url]: https://github.com/kkuchar2/distribution-data-generator/network/members
[stars-shield]: https://img.shields.io/github/stars/kkuchar2/distribution-data-generator.svg?style=flat-square
[stars-url]: https://github.com/kkuchar2/distribution-data-generator/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=flat-square
[issues-url]: https://github.com/kkuchar2/distribution-data-generator/issues
[license-shield]: https://img.shields.io/github/license/kkuchar2/distribution-data-generator?style=flat-square
[license-url]: https://github.com/kkuchar2/distribution-data-generator/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/kkuchar/
[product-screenshot]: images/screenshot.png
