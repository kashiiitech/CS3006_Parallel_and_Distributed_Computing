#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

void foo(int *b, int *a, int n) {
    #pragma omp parallel
    {
        int i, b_local[10];
        memset(b_local, 0, 10*sizeof(int));
        #pragma omp for 
        for(i = 0; i < n; i++) b_local[a[i]]++;


        #pragma omp critical
        {     
            for(i=0; i<10; i++) {
                b[i] += b_local[i]; 
            }
        }

    }
}

int main() {   
    int i;
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    int b2[10] = {0,1,2,3,4,5,6,7,8,9};
    int a[N];
    for(i=0; i<N; i++) a[i] = rand()%10;

    foo(b,a,N);
    for(i=0; i<N; i++) b2[a[i]]++;
    for(i=0; i<10; i++) printf("%d ", b[i]); puts("");
    for(i=0; i<10; i++) printf("%d ", b2[i]); puts("");
}