#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <stdio.h>

using namespace std;

int fun_dynamic();
int fun_static();

double time,start;


int main(){
	int num;
	cout << "Enter choice \n1. static\n2. Dynamic" << endl;
	cin >> num;
	 if(num == 1) static_fun();
	 
	 else if(num == 2) fun_dynamic();
	 
	 else return 0;
}



int fun_static ( ) {
	int i;
	start = omp_get_wtime();

	#pragma omp parallel for schedule(static) num_threads(4)
 	for (i = 0; i < 12; i++) {
		sleep(i);
		printf("Thread %d has completed iteration %d.\n",
		omp_get_thread_num( ), i);
 	}
	time = omp_get_wtime() - start;

 	printf("All done! Running time : %f \n",time);
 	return 0;
}



int fun_dynamic ( ) {
	int i;
 	double time,start;
	start = omp_get_wtime();

 	#pragma omp parallel for schedule(dynamic) num_threads(4)
 	for (i = 0; i < 12; i++) {
		sleep(i);
 		printf("Thread %d has completed iteration %d.\n",
		omp_get_thread_num( ), i);
 	}
  	time = omp_get_wtime() - start;

 	printf("All done! Running time : %f \n", time);
 	return 0;
}

