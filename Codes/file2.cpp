#include <iostream>
#include <chrono>
#include <thread>
#include <omp.h>

void function_1()
{
    std::cout<<"kashiiitech1"<<std::endl;
}

void function_2()
{
        std::cout<<"kashiiitech2"<<std::endl;
}


int main()
{
    #pragma omp parallel sections
    {    
        #pragma omp section
        function_1();
            
        #pragma omp section
        function_2();
    }

    return 0;
}
