# Overview

This is a simple set of useful classes and functions to use in any C++ applications on Linux, such as useful math functions (including variadic ones), functions that allow you to write error, warning, info, and other prompts, functions that simplify work with std::string and std::ifstream, classes that allow you to print boxes and tables containing useful information, etc. For more information, see the documentation.

# Requirements

- GNU GCC++17 or newer

# Installing

Run in your working directory to copy the repository

```sh
git clone https://github.com/Sergeyir/CppTools --depth=1
```

Run in the downloaded directory to compile the libraries (you can use option -jN to compile on multiple threads)

```sh 
make
```

There is also an option to generate the Makefile with cmake

```sh
cmake -B./build && cd build && make
```

# Documentation

Run in the downloaded directory to compile the libraries (you can use option -jN to compile on multiple threads). You can view the detailed documentation at https://sergeyir.github.io/documentation/CppTools/ (see Namespaces/Namespaces List/CppTools). Since this repository is not designed to be used on its own and is intended to be used as a set of libraries, every class, method, and variable is all in the CppTools namespace scope.

If the link is inaccessible, you can generate the documentation yourself with Doxygen. To do this run while in the root of the repository

```sh
doxygen
```

To view the generated HTML file, open html/index.html with any browser or simply run to open it on Linux

```sh
xdg-open html/index.html
```

# Usage
In order to use functions and classes from this project while compiling link libraries libBox.so, libTime.so, libTable.so, libIOTools.so, libStrTools.so, libErrorHandler.so (see $CPP_TOOLS_LIB in Makefile and Makefile.inc for more detail or see CMakeLists.txt), and don't forget to include the needed header files (see the list of files in the documentation https://sergeyir.github.io/documentation/CppTools/files.html).
