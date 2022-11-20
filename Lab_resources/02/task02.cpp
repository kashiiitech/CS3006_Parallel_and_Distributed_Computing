// <-- code by Kashiiitech -->
#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include<omp.h>

using namespace std;

int main()
{
  
	//int *arr = new int(n);
    string T;
    int count =0;
    string myText;

    ifstream file("f.txt");
	vector<string> myArray;
    while (getline (file, myText)) {
        stringstream X(myText);
        while (getline(X, T, ' ')) {  
            myArray.push_back(T);
        }
}
// parallel region
#pragma omp parallel num_threads(8) reduction(+:count)
{  
    #pragma omp for
    for (int i = 0; i < myArray.size(); i++)
    {   
        #pragma omp critical
        {
            count++;  // this is critical and it is used by one thread at a time.
        }
    }
    #pragma omp critical
    cout<<"I am thread no "<<omp_get_thread_num()<<" and my count is "<<count<<endl;
}

cout<<count<<endl;

}

