// Kashiiitech

#include <iostream>
#include <omp.h>


int main()
{
    int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int sum =0;

    #pragma omp parallel  num_threads(4) reduction(+ : sum)
    { 
    
        sum += a[omp_get_thread_num()];
    	sum += a[omp_get_thread_num()+4];
    	sum += a[omp_get_thread_num()+8];
    	sum += a[omp_get_thread_num()+12];
        sum += a[omp_get_thread_num()+16];
    	#pragma omp critical
    	std::cout<<"I am thread "<<omp_get_thread_num()<<"  "<<sum<<std::endl;
    
    
    }
    std::cout<<std::endl;
	std::cout<<sum<<std::endl;
    return 0;
}


