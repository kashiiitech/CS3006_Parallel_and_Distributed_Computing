#include <iostream>
#include <omp.h>

using namespace std;

void dynamic(){

cout<<"Dynamic"<<endl;

int i;

  #pragma omp parallel num_threads(4)
  {
    #pragma omp for schedule(dynamic)
    for (i = 0; i < 8; i++){
    #pragma omp critical
      cout<<"Iteration no "<<i<<" My thread id is: "<<omp_get_thread_num()<<endl;}
  }


}

void staticc(){

cout<<"Static"<<endl;

int i;

  #pragma omp parallel num_threads(4)
  {
    #pragma omp for schedule(static,2)
    for (i = 0; i < 8; i++){
    #pragma omp critical
      cout<<"Iteration no "<<i<<" My thread id is: "<<omp_get_thread_num()<<endl;}
  }

}



int main (void)
{

staticc();

cout<<endl;
cout<<endl;

dynamic();
  

  return 0;
}
