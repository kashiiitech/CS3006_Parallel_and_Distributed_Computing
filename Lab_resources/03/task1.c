#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[])
{
	// Use 4 threads when creating OpenMP parallel regions
	omp_set_num_threads(4);

	// Create the parallel region
	#pragma omp parallel
	{
		// Create the sections
		#pragma omp sections
		{
			// Generate the first section
			#pragma omp section
			{
				printf("I am Section 1 my thread num is  %d.\n", omp_get_thread_num());
			}

			// Generate the second section
			#pragma omp section
			{
				printf("I am Section 2 my thread num is  %d.\n", omp_get_thread_num());
			}
			
			#pragma omp section
			{
				printf("I am Section 3 my thread num is  %d.\n", omp_get_thread_num());
			}
			
			#pragma omp section
			{
				printf("I am Section 4 my thread num is  %d.\n", omp_get_thread_num());
			}
		}
	}

	return 0;
}

