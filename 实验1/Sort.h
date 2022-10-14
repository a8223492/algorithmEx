#pragma once
#ifndef SORT_H
#define SORT_H
#include <iterator>
#include <vector>
/*
* 在开始写算法的时候，就打算要实现一下c++ stl 类似的功能，但是发现自己的c++知识还是有点局限。
* 虽然写Sort是有泛型的，但是没实现algorithrm::sort()函数一样的参数，即使用两迭代器，不用指定模板类型，参数自动推导迭代器的类型。
* 本来考虑每个函数单独用template 指定模板类型，但是发现还是没法自动推导，之后会找时间学习学习stl的实现，现在这样实现Sort类倒是支持泛型了。
* 再看看能不能加入函数指针当谓词吧，我先试试
*/

template<typename T>
class Sort
{
	using iterator = typename std::vector<T>::iterator;
	using index_type = typename std::vector<T>::size_type;
	using size_type = typename std::vector<T>::size_type;
	using Arr = typename std::vector<T>;
	friend int main();
	

	
public:
	Sort(){}
	/*
	* 冒泡就没啥好说的，两个循环就ok。
	*/
	void bubbleSort(iterator begin, iterator end)//冒泡排序，end为尾后迭代器
	{
			for (auto i = begin; i != end - 1; ++i)
			{
				for (auto j = begin; j != end - 1; ++j)
				{
					if (*j < *(j + 1))
						std::swap(*j, *(j + 1));
				}
			}
	}
	/*
	* 选择排序，每一轮按顺序找次小值
	*/
	void selectionSort(iterator begin, iterator end)
	{
		for (auto i = begin; i != end; ++i)
			for (auto j = i + 1; j != end; ++j)
				if (*i > *j)
					std::swap(*i, *j);
			//走完一轮内层循环后，就找到当前一轮的最小值
		
	}
	/*
	* 插入排序，每一轮给最后元素找插入位置
	*/
	void insertionSort(iterator lt, iterator rt)
	{

		for (auto i = lt; i != rt - 1; ++i) 
		{
			iterator j, k;
			for (j = lt; j != i + 1 && *j < *(rt - 1); ++j)
			{
			}
			for (k = rt - 1; k != j; --k, std::swap(*k, *(k + 1)))
			{
			}
		}
	}
	/*
	* 希尔排序，利用gap分组，按组排序
	*/
	void shellSort(iterator lt, iterator rt)
	{
		int gap = 1;
		while (gap < std::distance(lt, rt) / 3)
			gap = 3 * gap + 1;
		
		while (gap >= 1)
		{
			for (auto i = lt; std::distance(i, rt) >gap; i += gap) //rt为尾后指针，distance(begin,end)即为两迭代器之间元素个数
			{//距离如果等于gap，则下一次i+=gap会让i指向end，尾后不存在的指针，所以不能等于gap
				iterator j, k;
				for (j = lt; j != i + gap && *j < *(i); j += gap){}
				//寻找到j位置，j要么到i处要么到一个比i位置元素要大的元素上
				//std::distance(j, k) >= gap操作要在前，此外std::swap要使用k-gap，否则迭代器会越界
				for (k = i; std::distance(j,k)>=gap; std::swap(*(k - gap ), *(k)), k -= gap ) {}
			}
			gap /= 3;
		}
	}
	/*
	* 分治法的典型应用
	*/
	void mergeSort(iterator lt, iterator rt)
	{
		if (std::distance(lt, rt) <= 1)
			return;
		auto mt = lt + std::distance(lt, rt) / 2;
		mergeSort(lt, mt);
		mergeSort(mt, rt);
		Arr arr;
		Arr arrl(lt, mt);
		Arr arrr(mt, rt);
		index_type i = 0, j = 0, lend = arrl.size(), rend = arrr.size();
		while (i < lend && j < rend)
		{
			if (arrl[i] > arrr[j])
			{
				arr.push_back(arrr[j]);
				++j;
			}
			else
			{
				arr.push_back(arrl[i]);
				++i;
			}
		}
		while (i < lend) {
			arr.push_back(arrl[i]);
			++i;
		}
		while (j < rend) {
			arr.push_back(arrr[j]);
			++j;
		}
		std::copy(arr.begin(), arr.end(), lt);
	}
	/*
* 当时写的时候，在临界条件一直搞不清
* 写代码果然还是要用纸打草稿的
* 关于是先--j还是--i,顺序不对会导致停下来的指针位置不是最合适的
*/
	void quickSort(iterator lt, iterator rt)
	{
		if (std::distance(lt, rt) <= 1)
			return;
		auto i = lt;
		auto j = rt - 1;
		auto pivot = *lt;
		while (i < j)
		{
			while (i < j && *j >= pivot)
				--j;
			while (i < j && *i <= pivot)
				++i;
			if (i != j)
				std::swap(*i, *j);
		}
		std::swap(*lt, *i);
		quickSort(lt, i);
		quickSort(i + 1, rt);
	}
	/*
	* 由于单函数不好表示heapSort，故而单独写了个Heap类封装建堆、排序逻辑。
	* Heap类直接设为私有类，把Sort作为Heap类的友元，我感觉这样设计蛮合理，毕竟只有我这个Sort应该要用Heap，其他人又不用。
	* 因为之前写的，没用迭代器，所以用copy封装了一下。感觉这样效率蛮低的，c++右移是不是能让效率高点？移动迭代器？以后学学这种实现的best pratice
	*/
	void heapSort(iterator begin,iterator end)
	{
		Arr arr(std::distance(begin, end));
		std::copy(begin, end, arr.begin());
		Heap heap(arr);
		std::copy(arr.begin(), arr.end(), begin);
	}
	

	private:
		class Heap {
			using iterator = typename std::vector<T>::iterator;
			using index_type = typename std::vector<T>::size_type;
			using size_type = typename std::vector<T>::size_type;
		public:
			Heap(std::vector<T>& arr) {
				//利用上浮方法建堆	
				for(auto i = arr.size()/2  - 1; i > 0 ; --i) 
				{
					swim(arr, i - 1, arr.size());
				}
						
				//利用上浮一个个取出元素
				for (index_type  heapSize = arr.size() - 1; heapSize > 0; --heapSize)
				{
					std::swap(arr[0], arr[heapSize]);
					swim(arr, 0, heapSize);
				}
			}
			void swim(std::vector<T>& arr, index_type parentIndex,size_type heapLength) {
				size_type maxNodeIndex = maxIndex(arr, parentIndex, heapLength);
				if (maxNodeIndex != parentIndex) {
					std::swap(arr[maxNodeIndex], arr[parentIndex]);
					swim(arr, maxNodeIndex,heapLength);
				}
			}
			index_type leftIndex(index_type i) { return 2 * i + 1; }
			index_type rightIndex(index_type i) { return 2 * i + 2; }
			index_type maxIndex(std::vector<T>& arr, index_type parentIndex, size_type heapSize) {
				index_type maxIndex = parentIndex;//初始时默认父节点最大
				index_type leftIndex = Heap::leftIndex(parentIndex);
				if (leftIndex < heapSize)//检测是否越界
					maxIndex = (arr[leftIndex] > arr[maxIndex] ? leftIndex : maxIndex);//如果左孩子大于父节点，
				index_type rightIndex = Heap::rightIndex(parentIndex);
				if (rightIndex < heapSize)
					maxIndex = (arr[rightIndex] > arr[maxIndex] ? rightIndex : maxIndex);
				return maxIndex;
			}


		};
};

#endif // !SORT_ALGORITHM_H
