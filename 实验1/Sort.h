#pragma once
#ifndef SORT_H
#define SORT_H
#include <iterator>
#include <vector>
/*
* �ڿ�ʼд�㷨��ʱ�򣬾ʹ���Ҫʵ��һ��c++ stl ���ƵĹ��ܣ����Ƿ����Լ���c++֪ʶ�����е���ޡ�
* ��ȻдSort���з��͵ģ�����ûʵ��algorithrm::sort()����һ���Ĳ�������ʹ����������������ָ��ģ�����ͣ������Զ��Ƶ������������͡�
* ��������ÿ������������template ָ��ģ�����ͣ����Ƿ��ֻ���û���Զ��Ƶ���֮�����ʱ��ѧϰѧϰstl��ʵ�֣���������ʵ��Sort�൹��֧�ַ����ˡ�
* �ٿ����ܲ��ܼ��뺯��ָ�뵱ν�ʰɣ���������
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
	* ð�ݾ�ûɶ��˵�ģ�����ѭ����ok��
	*/
	void bubbleSort(iterator begin, iterator end)//ð������endΪβ�������
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
	* ѡ������ÿһ�ְ�˳���Ҵ�Сֵ
	*/
	void selectionSort(iterator begin, iterator end)
	{
		for (auto i = begin; i != end; ++i)
			for (auto j = i + 1; j != end; ++j)
				if (*i > *j)
					std::swap(*i, *j);
			//����һ���ڲ�ѭ���󣬾��ҵ���ǰһ�ֵ���Сֵ
		
	}
	/*
	* ��������ÿһ�ָ����Ԫ���Ҳ���λ��
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
	* ϣ����������gap���飬��������
	*/
	void shellSort(iterator lt, iterator rt)
	{
		int gap = 1;
		while (gap < std::distance(lt, rt) / 3)
			gap = 3 * gap + 1;
		
		while (gap >= 1)
		{
			for (auto i = lt; std::distance(i, rt) >gap; i += gap) //rtΪβ��ָ�룬distance(begin,end)��Ϊ��������֮��Ԫ�ظ���
			{//�����������gap������һ��i+=gap����iָ��end��β�󲻴��ڵ�ָ�룬���Բ��ܵ���gap
				iterator j, k;
				for (j = lt; j != i + gap && *j < *(i); j += gap){}
				//Ѱ�ҵ�jλ�ã�jҪô��i��Ҫô��һ����iλ��Ԫ��Ҫ���Ԫ����
				//std::distance(j, k) >= gap����Ҫ��ǰ������std::swapҪʹ��k-gap�������������Խ��
				for (k = i; std::distance(j,k)>=gap; std::swap(*(k - gap ), *(k)), k -= gap ) {}
			}
			gap /= 3;
		}
	}
	/*
	* ���η��ĵ���Ӧ��
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
* ��ʱд��ʱ�����ٽ�����һֱ�㲻��
* д�����Ȼ����Ҫ��ֽ��ݸ��
* ��������--j����--i,˳�򲻶Իᵼ��ͣ������ָ��λ�ò�������ʵ�
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
	* ���ڵ��������ñ�ʾheapSort���ʶ�����д�˸�Heap���װ���ѡ������߼���
	* Heap��ֱ����Ϊ˽���࣬��Sort��ΪHeap�����Ԫ���Ҹо���������������Ͼ�ֻ�������SortӦ��Ҫ��Heap���������ֲ��á�
	* ��Ϊ֮ǰд�ģ�û�õ�������������copy��װ��һ�¡��о�����Ч�����͵ģ�c++�����ǲ�������Ч�ʸߵ㣿�ƶ����������Ժ�ѧѧ����ʵ�ֵ�best pratice
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
				//�����ϸ���������	
				for(auto i = arr.size()/2  - 1; i > 0 ; --i) 
				{
					swim(arr, i - 1, arr.size());
				}
						
				//�����ϸ�һ����ȡ��Ԫ��
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
				index_type maxIndex = parentIndex;//��ʼʱĬ�ϸ��ڵ����
				index_type leftIndex = Heap::leftIndex(parentIndex);
				if (leftIndex < heapSize)//����Ƿ�Խ��
					maxIndex = (arr[leftIndex] > arr[maxIndex] ? leftIndex : maxIndex);//������Ӵ��ڸ��ڵ㣬
				index_type rightIndex = Heap::rightIndex(parentIndex);
				if (rightIndex < heapSize)
					maxIndex = (arr[rightIndex] > arr[maxIndex] ? rightIndex : maxIndex);
				return maxIndex;
			}


		};
};

#endif // !SORT_ALGORITHM_H
