# Overview

This is a simple set of useful classes and functions to use in any cpp applications on linux.

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

# Documentation

You can view the detailed documentation https://sergeyir.github.io/CppTools/ (see Namespaces / Namespaces List / CppTools). Since this repository is not designed to be used on it's own and is intended to be used as a set of libraries every class, method, and variable are all in CppTools namespace scope.

If the link is unaccesible you can generate the documentation yourself with doxygen. To do this run while in root of the repository

```sh
doxygen
```

To view the generated html file open html/index.html with any browser or simply run to automaticaly open it on linux

```sh
xdg-open html/index.html
```

# Usage

In order to use functions and classes from this project while compiling link libraries libBox.so, libTime.so, libTable.so, libIOTools.so, libStrTools.so, libErrorHandler.so (see $CPP_TOOLS_LIB in Makefile and Makefile.inc for more detail) and don't forget to include the needed header files (see list of files in documentation https://sergeyir.github.io/CppTools/files.html).
