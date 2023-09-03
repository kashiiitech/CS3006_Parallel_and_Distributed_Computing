#include <iostream>
#include <vector>
#include <omp.h>

void print_iterations(const std::vector<int>& iterations)
{
    int index = 0;
    for (const auto i : iterations)
    {
        std::cout << "Thread " << index++ << " -> " << i << " iterations" << std::endl;
    }
  
}


int main()
{
    std::vector<int> iterations(5, 0);
    int n = 1000;

    #pragma omp parallel shared(iterations, n) num_threads(10)
    {    
        #pragma omp for 
        for (int i = 0; i < n; i++)
        {
            iterations[omp_get_thread_num()]++;
        }
    }

    print_iterations(iterations);
    return 0;
}


