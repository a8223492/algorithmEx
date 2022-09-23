#pragma once
#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H
#include <iterator>
#include <vector>
#include "Heap.h"

class Sort
{
	friend int main();
	typedef std::vector<int>::iterator iterator;
	typedef std::vector<int>::size_type size_type;
	typedef std::vector<int> Arr;
	typedef std::vector<int>::size_type index_type;

public:
	void bubbleSort(iterator lt, iterator rt, size_type count)
	{
		if (!check(count))
		{
			for (auto i = lt; i != rt; ++i)
			{
				for (auto j = lt; j != rt; ++j)
				{
					if (*j < *(j + 1))
						std::swap(*j, *(j + 1));
				}
			}
		}
	}
	void selectionSort(iterator lt, iterator rt, size_type count)
	{
		if (!check(count))
		{
			for (auto i = lt; i != rt; ++i)
			{
				for (auto j = lt; j != rt; ++j)
				{
					auto temp = j;
					auto least = j;
					if (*temp < *least)
						least = temp;
					std::swap(*least, *i);
				}
			}
		}
	}
	void insertionSort(iterator lt, iterator rt)
	{

		for (auto i = lt; i != rt - 1; ++i) // i��ʾ�ź����λ��
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
	void shellSort(iterator lt, iterator rt)
	{
		int gap = 1;
		while (gap < std::distance(lt, rt) / 3)
		{
			gap = 3 * gap + 1;
		}
		while (gap >= 1)
		{
			for (auto i = lt; i != rt - 1; i += gap) // i��ʾ�ź����λ��
			{
				iterator j, k;
				for (j = lt; j != i + 1 && *j < *(rt - 1); j += gap)
				{
				}
				for (k = rt - 1; k != j; k -= gap, std::swap(*k, *(k + 1)))
				{
				}
			}
			gap /= 3;
		}
	}
	void heapSort(std::vector<int> &arr)
	{
		Heap heap(arr);
		for (auto i = 0, heapSize = 5; i != 5; ++i)
		{
			std::swap(arr[0], arr[--heapSize]);
			heap.sink(arr, 0, heapSize);
		}
	}
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
		while(i<lend){
			arr.push_back(arrl[i]);
			++i;
		}
		while(j<rend){
			arr.push_back(arrr[j]);
			++j;
		}
		std::copy(arr.begin(), arr.end(), lt);
	}

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
	bool check(size_type)
	{
		return 0;
	}
};

#endif // !SORT_ALGORITHM_H
