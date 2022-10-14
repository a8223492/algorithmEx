#pragma once
#ifndef SORT_NC_H
#define SORT_NC_H
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
/*
* 
*/
class Sortnc
{
	friend int main();
	typedef std::vector<int>::iterator iterator;
	typedef std::vector<int>::size_type size_type;
	typedef std::vector<int> Arr;
	typedef std::vector<int>::size_type index_type;
	typedef std::vector<std::list<int>> Buckets;
public:
	void countSort(iterator begin, iterator end) {
		
		Arr temp;
		auto max = *std::max_element(begin, end);
		auto min = *std::min_element(begin, end);
		std::vector<std::pair<int, size_type>> bucket;
		for (int i = min; i <= max; ++i)
			bucket.push_back(std::pair<int,size_type> (i,0));
		auto i = begin;
		auto j = bucket.begin();
		for (; i != end; ++i) {	
			++bucket[(*i) - min].second;
		}
		for (auto i : bucket) {
			while (i.second != 0)
			{
				temp.push_back(i.first);
				--i.second;
			}
		}
		std::copy(temp.begin(), temp.end(),begin);
	}
	void bucketSort(iterator begin, iterator end) {
		auto max = *std::max_element(begin, end);
		auto min = *std::min_element(begin, end);
		size_type k = 10, length = std::distance(begin, end);
		auto bucketsNum = (max - min) / k + 1;
		Buckets buckets(bucketsNum);
		for (auto i = begin; i!= end; ++i)
			buckets[(*i - min) / k].push_back(*i);
		Arr result;
		for (auto i : buckets) {
			i.sort([](auto l, auto r) {return l < r; });
			for (auto j : i)
				result.push_back(j);
		}
		std::copy(result.begin(), result.end(), begin);
	}
	void radixSort(iterator begin, iterator end) {
		auto max = *std::max_element(begin, end);
		auto length = std::distance(begin, end);
		auto MaxBit = [](auto max) {
			auto maxBit = 1;
			while (max / 10 != 0) 
			{
			max = max / 10;
			maxBit++;
			}
			return maxBit;
		};
		auto chooseBucket = [](auto value,auto bit){
			auto bucketNum = 0;
			size_type bitNow = 0;
			while (bitNow != bit) {
				bucketNum = value % 10;
				value /= 10;
				++bitNow;
			}
			return bucketNum;
		};
		auto maxBit = MaxBit(max);
		
		for (auto bit = 1; bit <= maxBit; ++bit) {
			Buckets buckets(10);
			for (auto i = begin; i != end; ++i) {
				buckets[chooseBucket(*i, bit)].push_back(*i);
			}
			auto it = begin;
			for (auto i : buckets) {
				for (auto j : i)
					*(it++) = j;
			}
			buckets.clear();
		}
	}
};


#endif