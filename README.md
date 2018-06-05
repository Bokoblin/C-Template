# C-Template

[![Build Status](https://travis-ci.com/Bokoblin/C-Template.svg?branch=master)](https://travis-ci.com/Bokoblin/C-Template)
[![CodeFactor](https://www.codefactor.io/repository/github/bokoblin/c-template/badge)](https://www.codefactor.io/repository/github/bokoblin/c-template)

### Description

This repository hosts a template structure for language C.


### Authors

* JOLIVET Arthur [jolivet.arthur@gmail.com](mailto:jolivet.arthur@gmail.com)


### Tools used

- IDEs : Clion
- Language: C
- Libraries:
    - None


### Documentation

The documentation can be generated using Doxygen.


### How to build

#### Requirements

To build the project, the following programs must be installed and reachable from `PATH`:
- make
- gcc / clang

You can optionally need those programs:
- cmake
- doxygen

#### Instructions

You can build the project using either make or CMake.

By using make, the following commands are available in the `Makefile`:

```
make [all]   #Defaulting to make build
make help    #To show the available commands
make build   #To build the project
make test    #To build and start the tests
make vtest   #To build and start the tests with valgrind check
make ctest   #To build and start the tests with coverage
make install #To install the project
make run     #To run program once installed (make install before required)
make vrun    #To run program once installed (make install before required) with valgrind check
make clean   #To remove objects files, executables and installation
make docs    #To generate documentation with doxygen in /doc (open /doc/html/index.html in your browser)
```
    
By using CMake, please execute the following commands:

```
mkdir build
cd build
cmake .. && make
```


### Licence

This template is licensed under Apache License 2.0.
