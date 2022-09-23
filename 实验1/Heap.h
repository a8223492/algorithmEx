#pragma once
#ifndef HEAP_H
#define HEAP_H
#include<iterator>
#include<vector>
#include"sortAlgorithm.h"
/**
* @brief 堆排序封装的类
* 默认为大根堆来获得升序序列
* @function swim:通过将堆顶元素与堆的最后元素替换来取出堆中最大元素，并通过将元素上浮到合适的位置来恢复堆的有序性
*/
class Heap {
	typedef  std::vector<int>::iterator iterator;
	typedef std::vector<int>::size_type index_type;
	typedef std::vector<int>::size_type size_type;
	friend class Sort;
	friend int main();

private:
	Heap(std::vector<int>& arr) {//利用上浮方法建堆	
		for (auto i = arr.size() / 2 - 1;; --i) {
			swim(arr, i);
			if (i == 0)
				break;
		}
	}
	void swim(std::vector<int>& arr, index_type parentIndex) {
		size_type maxNodeIndex = maxIndex(arr, parentIndex, arr.size());
		if (maxNodeIndex != parentIndex) {
			std::swap(arr[maxNodeIndex], arr[parentIndex]);
			swim(arr, maxNodeIndex);
		}
	}
	void sink(std::vector<int>& arr, index_type parentIndex, size_type heapSize) {

		size_type maxNodeIndex = maxIndex(arr, parentIndex, heapSize);
		if (maxNodeIndex != parentIndex) {
			std::swap(arr[maxNodeIndex], arr[parentIndex]);
			sink(arr, parentIndex, heapSize);
		}
	}
	index_type parentIndex(index_type i) { return (i - 1) / 2; }
	index_type leftIndex(index_type i) { return 2 * i + 1; }
	index_type rightIndex(index_type i) { return 2 * i + 2; }
	index_type maxIndex(std::vector<int>& arr, index_type parentIndex, size_type heapSize) {
		index_type maxIndex = parentIndex;//初始时默认父节点最大
		index_type leftIndex = Heap::leftIndex(parentIndex);
		if (leftIndex < heapSize)
			maxIndex = (arr[leftIndex] > arr[maxIndex] ? leftIndex : maxIndex);
		index_type rightIndex = Heap::rightIndex(parentIndex);
		if (rightIndex < heapSize)
			maxIndex = (arr[rightIndex] > arr[maxIndex] ? rightIndex : maxIndex);
		return maxIndex;
	}


};
#endif