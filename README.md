# MANGO [![Build Status](https://travis-ci.org/hiddenSymmetries/mango.svg?branch=master)](https://travis-ci.org/hiddenSymmetries/mango) 

Multiprocessor Algorithms for Nonlinear Gradient-free Optimization

**View the [main documentation here.](https://hiddensymmetries.github.io/mango/)**

MANGO is a library for optimization using MPI parallelism. It provides
a common interface for calling other optimization libraries, including non-parallel algorithms,
making them parallel by providing parallelized finite-difference gradient calculations. Some of MANGO's features are the following:

* MANGO makes it possible to try out different optimization libraries and algorithms without recompiling your code. The library and algorithm can be chosen with a runtime option.
* MANGO provides a common interface to access multiple optimization libraries. At present, MANGO has support for [GSL](https://www.gnu.org/software/gsl/doc/html/), [PETSc/TAO](https://www.mcs.anl.gov/petsc/), [NLOpt](https://nlopt.readthedocs.io/en/latest/), and [HOPSPACK](https://dakota.sandia.gov/packages/hopspack). 
* MANGO has minimal dependencies, requiring nothing more than MPI. If any of the libraries above are not available on your system, MANGO can be built without them.
* At present, MANGO is focused on optimization problems for which derivatives are not available. MANGO allows any derivative-based algorithm in the above libraries to be used with finite-difference gradients that are evaluated concurrently.
* MPI parallelism is allowed within the objective function, both for optimization algorithms that are serial and parallel. For parallel algorithms with parallelization within the objective function, MANGO helps you partition the available processors into worker groups.
* MANGO is presently callable from C++, C, and Fortran. Python support is planned in the future.
* MANGO includes algorithms both for nonlinear least-squares problems and conventional optimization. If your problem has least-squares structure and you want to try a non-least-squares algorithm, you don't need to do anything other than select the desired algorithm - MANGO will automatically convert the residuals to a single objective function.
* MANGO presently includes support for (optional) bound constraints. Support for nonlinear equality and inequality constraints is planned.
* MANGO includes a collection of test problems, which allow you to compare existing algorithms and try out new ones.
* For reliability, MANGO includes unit tests, integrated tests, regression tests, and continuous integration.

MANGO is being developed as part of the [Collaboration on Hidden Symmetries and Fusion Energy](https://hiddensymmetries.princeton.edu/). This work is supported by a grant from the Simons Foundation (560651, M.L.).

# Compile instruction for Ubuntu system

Steps:
  1. git clone https://github.com/luzhiyuann/mango.git
  2. cd mango
  4. cd /external_external_packages
  5. ./install_nlopt.sh and sudo apt install libnlopt-dev
  6. ./install_catch2.sh
  7. ./install_eigen.sh
  8. sudo apt install libgsl-dev
  9. sudo apt install petsc-dev
  10. cd ..
  11. make -j n

Notes:
  1. if the compile process outputs: warning: Clock skew detected. Your build may be incomplete.
     1.1 find . -type f | xargs touch   # in the mango directory
     1.2 make clean
     1.3 make -j n
  2. The Parallel compilers of STELLOPT and MANGO library should keep consistent.
