// Kashiiitech
#include <iostream>
#include <omp.h>
using namespace std;


int main()
{

    omp_set_num_threads(8);

    #pragma omp parallel
    { 
        cout<<"Hello world!! I am Process:: "<<omp_get_thread_num()<<endl;   
    }
    return 0;
}


