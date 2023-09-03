// Enable OpenMP in Properties -> C / C++ -> Language
//#include "stdafx.h"
#include <iostream>
#include <omp.h>
#include <stdio.h>

#define N 16

using namespace std;

void printVar(int a[], int b, int c, int d, int m) {
cout << "b = " << b << ", c = " << c << ", d = " << d << " m = " << m << endl;
cout << "a = ";
for (int i = 0; i < N; i++)
cout << a[i] << ", ";
cout << endl;
}
int main(){
int i;
int a[N];
int b = 0, c = 0, d = 0, m = 0;
cout << "Before par. for" << endl;
printVar(a, b, c, d, m); //Garbage Values

#pragma omp parallel for default(none) private(i,b) firstprivate(c) lastprivate(d) shared(m,a) schedule(static, 3) num_threads(4)
for (i = 0; i < N; i++) {
// b and d must be initialized
b = 100;
d = 10;
printf("Thread %d, iteration %d: b = %d, c = %d, d = %d, m = %d\n", omp_get_thread_num(), i, b, c, d, m);
a[i] = omp_get_thread_num();
b = omp_get_thread_num();
c = omp_get_thread_num();
d = omp_get_thread_num();
m = omp_get_thread_num();
}
cout << "After par. for" << endl;
printVar(a, b, c, d, m);
getchar();
return 0;
}
