#include<iostream>
#include<omp.h>

using namespace std;

void factorial(int n) {
    int fac = 1;
        if (n < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= n; ++i) {
            fac *= i;
        }
        cout << "Factorial of " << n << " = " << fac;    
    }
}


int fib(int n)

{
	if (n <= 1)	//stopping condition

		return n;

	else	//recursive part

		return (fib(n - 1) + fib(n - 2));

}




int main()
{

    int n;
    cin>>n;

 omp_set_num_threads(2);
    
// parallel region
#pragma omp sections
{
    #pragma omp section
    { 
        factorial(n);  // task-1
        cout<<endl;
    }

    #pragma omp section
    { 
        cout<<"Fibonacci of "<<n<<" is "<<fib(n)<<endl; //task-2
    }
}

    return 0;
}