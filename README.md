# min-contracts

[![Linux builds](https://github.com/jdgarciauc3m/min-contracts/actions/workflows/linux.yml/badge.svg)](https://github.com/jdgarciauc3m/min-contracts/actions)

[![MacOS builds](https://github.com/jdgarciauc3m/min-contracts/actions/workflows/macos.yml/badge.svg)](https://github.com/jdgarciauc3m/min-contracts/actions)

[![Windows builds](https://github.com/jdgarciauc3m/min-contracts/actions/workflows/windows.yml/badge.svg)](https://github.com/jdgarciauc3m/min-contracts/actions)

Minimal contracts library tries to offer a minimal library-only solution to support contracts in 
modern C++.

The library offers:
  * Preconditions
  * Postconditions
  * Assertions

Please, refer to library [API description](doc/mincontracts.md) for more details.

# Getting started

## Prerequisites

The following requirements must be met to use the library:
  * **CMake 3.16** or higher.
  * A **C++20** compliant compiler. Note that the library has 
    been tested with the following versions:
      * g++ (version 9, 10, 11) under Ubuntu Linux 20.
      * clang++ (version 11) under Ubuntu Linux 20.
      * AppleClang++ (version 12) under MacOS 10.
      * MSVC 2019 under Windows 2019.
      * MSVC 2017 under Windows 2017.
    
If you want to run the unit tests you will need:
  * Google Test (available at [GitHub repo](https://github.com/google/googletest)).
    Please, use the latest available version.
    If Google Test library is not found, the unit tests will not be available but
    you will be able to install the library.
    
## Running the tests

Unit tests can be disabled by setting the option `mincontracts_TESTS` to `OFF`.

To run the tests, simply use CTest, from the build directory, passing the desired 
configuration.

```shell
ctest
```

If you want more verbose output for the tests, you can use:

```shell
ctest -VV
```

# Acknowledgments

Some ideas used here are inspired by the great series of blog posts by Herb Sutter:
  * [GotW #98 Solution: Assertion levels](https://herbsutter.com/2021/01/25/gotw-98-solution-assertion-levels-difficulty-5-10/)
  * [GotW #99 Solution: Postconditions](https://herbsutter.com/2021/02/08/gotw-99-solution-postconditions-difficulty-7-10/)
  * [GotW #100 Solution: Preconditions, Part 1](https://herbsutter.com/2021/02/25/gotw-100-solution-preconditions-part-1-difficulty-8-10/)
  * [GotW #101 Solution: Preconditions, Part 2](https://herbsutter.com/2021/03/25/gotw-101-solution-preconditions-part-2-difficulty-7-10/)