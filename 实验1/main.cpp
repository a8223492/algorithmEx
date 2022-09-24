#include"sortAlgorithm.h"
#include<iostream>
#include <algorithm>
#include <vector>

#include <chrono>
using namespace std;


int main() {
    
    
    vector<int> arr = { 1,2,3,4,5,6 };
    auto lt = arr.begin() + 1;
    auto rt = arr.end() - 1;
    vector<int> arr1(lt, rt);
    auto iit = std::inserter(arr, lt);
    
    
    int Num = 5;
    vector<int> temp;
    
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin(), temp.end());
    
	//Sort sort;
	//sort.heapSort(arr);
	Sort sort;
    sort.shellSort(temp.begin(), temp.end());

    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	/*sort.quickSort(temp.begin(), temp.end());*/
    sort.bubbleSort(temp.begin(), temp.end() - 1,10);

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "run time = " << time_used.count() << " seconds. " << endl;
	
}

