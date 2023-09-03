// <-- code by Kashiiitech -->
#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include<omp.h>
#include<stdlib.h>
#include <bits/stdc++.h>


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

    sort(myArray.begin(),myArray.end());
    string target;
    // int countt=0;
    int countt = 0;
    for (int i = 0; i < myArray.size(); i++)
    {
        target = myArray[i];
        countt = std::count(myArray.begin(), myArray.end(), target);
        std::cout << countt << std::endl;  

    }
    


}



