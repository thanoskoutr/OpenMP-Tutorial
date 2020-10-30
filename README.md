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

