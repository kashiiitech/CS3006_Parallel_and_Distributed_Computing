// Code by Kashiiitech
// without using reduction clause
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
#pragma omp parallel num_threads(8)
{  int sum=0;
    #pragma omp for
    for (int i = 0; i < myArray.size(); i++)
    {    
        #pragma omp critical
        {
           
            sum++;  // this is critical and it is used by one thread at a time.
        }
        count+=sum;
    }
    #pragma omp critical
    cout<<"I am thread no "<<omp_get_thread_num()<<" and my count is "<<sum<<endl;
}

cout<<count<<endl;

}

