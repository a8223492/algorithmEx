
#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <chrono>
#include"Sort.h"
#include"Sortnc.h"
#include"Puzzle.h"
using namespace std;

int main() {
	
	//Sort<int> sort;
	//Sortnc sortnc;
	//vector<int> arr;
	//vector<vector<int>> arrs;
	//int Num = 100000;
	//cout << "O(N^2) algos Sort " << Num << " numbers" << endl;
	//for (int i = 0; i < Num; ++i)
	//{
	//	arr.push_back(i + 1);
	//}
	//random_shuffle(arr.begin(), arr.end());

	//for (auto i = 0; i < 3; ++i) {
	//	arrs.push_back(arr);
	//}
	//auto t1 = chrono::steady_clock::now();
	//sort.bubbleSort(arrs[0].begin(), arrs[0].end());
	//auto t2 = chrono::steady_clock::now();
	//auto time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "bubbleSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sort.selectionSort(arrs[1].begin(), arrs[1].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "selectionSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sort.insertionSort(arrs[2].begin(), arrs[2].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "insertionSort run time = " << time_used.count() << " milliseconds. " << endl;
	//Num = 10000000;
	//cout << "other algos Sort " << Num << " numbers" << endl;
	//arr.clear();
	//for (int i = 0; i < Num; ++i)
	//{
	//	arr.push_back(i + 1);
	//}
	//random_shuffle(arr.begin(), arr.end());
	//for (auto i = 0; i < 8; ++i) {
	//	arrs.push_back(arr);
	//}
	//t1 = chrono::steady_clock::now();
	//sort.shellSort(arrs[1].begin(), arrs[1].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "shellSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sort.mergeSort(arrs[2].begin(), arrs[2].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "mergeSort run time = " << time_used.count() << " milliseconds. " << endl;
	// t1 = chrono::steady_clock::now();
	//sort.quickSort(arrs[3].begin(), arrs[3].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "quickSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//std::sort(arrs[4].begin(), arrs[4].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "std::sort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sort.heapSort(arrs[6].begin(), arrs[6].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "heapSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sortnc.countSort(arrs[5].begin(), arrs[5].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "countSort run time = " << time_used.count() << " milliseconds. " << endl;
	// t1 = chrono::steady_clock::now();
	//sortnc.bucketSort(arrs[7].begin(), arrs[7].end());
	// t2 = chrono::steady_clock::now();
	// time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "bucketSort run time = " << time_used.count() << " milliseconds. " << endl;
	//t1 = chrono::steady_clock::now();
	//sortnc.radixSort(arrs[0].begin(), arrs[0].end());
	//t2 = chrono::steady_clock::now();
	//time_used = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	//cout << "radixSort run time = " << time_used.count() << " milliseconds. " << endl;

	Puzzle p;
	p.doors();

	p.openedDoors();


}

