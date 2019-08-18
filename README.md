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
* [Contributing](#contributing)
* [License](#license)

<!-- ABOUT THE PROJECT -->
## About The Project

This is simple project implementing generation of files:
 - containing distribution data (laplace / normal / uniform)
 - data samples from distribution files

<!-- GETTING STARTED -->
## Getting Started

1. Clone the repo

  ```sh
  git clone https://github.com/kkuchar2/distribi
  ```

2. Make sure you've installed Boost libraries on your machine

  ```sh
    sudo apt-get install libboost-all-dev
  ```

3. Build executable
```sh
  cd distribution-data-generator
  mkdir build
  cd build
  cmake ..
  make
```

3. To show help run
```sh
  ./ddgenerator -h
```

## Usage


```sh
  # Generate file with distribution data
  ./ddgenerator --generator --distribution [laplace | normal | uniform] -output_file [OUT] --mean [MEAN]

  # Generate data samples using distribution file
  ./ddgenerator --data --input_file [DISTRIBUTION_FILE] --output_file [OUT] --sample_count [SAMPLE_COUNT]

  # Note:
  --mean parameter is used for laplace and normal distribution only.
```

## Contributing

Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

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
