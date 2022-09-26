#include"sortAlgorithm.h"
#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <chrono>
#include"Sortnc.h"
#include"Puzzle.h"
using namespace std;

int main() {
    Puzzle p;
    p.threeBottle();
    
 //   vector<int> arr = { 5,4,3,2,1,0 };
	//Sort sort;
	
 //   auto lt = arr.begin() + 1;
 //   auto rt = arr.end() - 1;
 //   vector<int> arr1(lt, rt);
 //   auto iit = std::inserter(arr, lt);
 //   
 //   
    int Num = 10000;
    vector<int> temp;
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin(), temp.end());
    Sortnc sortnc;
	////Sort sort;
	////sort.heapSort(arr);
	//Sort sort;
 //   sort.shellSort(temp.begin(), temp.end());
    
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	/*sort.quickSort(temp.begin(), temp.end());*/
    /*sort.bubbleSort(temp.begin(), temp.end() - 1,10);*/
    /*sort.mergeSort(temp.begin(), temp.end());*/
    sortnc.radixSort(temp.begin(), temp.end());

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "run time = " << time_used.count() << " seconds. " << endl;
	
}

