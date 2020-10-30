# OpenMP-Tutorial
This repository contains exercises and solutions in C from an OpenMP tutorial by Tim Mattson. It covers the basic directives and constructs of OpenMP in order to parallelize serial programs.

# Structure
The problems and their respective solutions are the following:
1. `hello.c`
2. `pi.c` -> `pi_spmd_simple.c`, `pi_spmd_final`, `pi_loop`
3. `mandel.c` -> `mandel_par.c`
4. `linked.c` -> `linked_par.c`, `linked_tasks.c`

# Build the programs
In order to build all the programs, just run the makefile:
```
make
```
Currently it is only tested on Linux environment.

# Resources
The tutorial is "Introduction to OpenMP" by Tim Mattson and can be found in the OpenMP's site, 
under [Resources/Tutorials & Articles](https://www.openmp.org/resources/tutorials-articles/) 
allong with other OpenMP tutorials.

All the exercise files can be found in his [repository](https://github.com/tgmattso/OpenMP_intro_tutorial).
