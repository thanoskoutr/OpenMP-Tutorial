/*
NAME: PI SPMD ... a simple version.
This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.
The program was parallelized using OpenMP and an SPMD 
algorithm.  The following OpenMP specific lines were 
added: 
(1) A line to include omp.h -- the include file that 
contains OpenMP's function prototypes and constants.
(2) A pragma that tells OpenMP to create a team of threads
with an integer variable i being created for each thread.
(3) two function calls: one to get the thread ID (ranging
from 0 to one less than the number of threads), and the other
returning the total number of threads.
(4) A cyclic distribution of the loop by changing loop control
expressions to run from the thread ID incremented by the number 
of threads.  Local sums accumlated into sum[id].

Note that this program will show low performance due to 
false sharing.  In particular, sum[id] is unique to each
thread, but adfacent values of this array share a cache line
causing cache thrashing as the program runs.

History: Written by Tim Mattson, 11/99.
*/

#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
static long num_steps = 100000000;
double step;

int main ()
{
	int i;
	int nthreads;
	double pi;
	double sum[NUM_THREADS];
	double start_time, run_time;

	step = 1.0 / (double) num_steps;

	start_time = omp_get_wtime();

	omp_set_num_threads(NUM_THREADS);
	
#pragma omp parallel
	{
		int i, id, nthrds;
		double x;

		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		printf("num_threads = %d\n", nthrds);

		if (id == 0)
		{
			nthreads = nthrds;
		}

		for (i = id, sum[id] = 0.0; i < num_steps; i = i + nthrds)
		{
			x = (i + 0.5) * step;
			sum[id] += 4.0 / (1.0 + x*x);
		}
	}
	
	for(i = 0, pi = 0.0; i < nthreads; i++)
	{
		pi += sum[i] * step;
	}

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n", num_steps, pi, run_time);
	return 0;
}
