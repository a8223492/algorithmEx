#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include<iostream>
#include<vector>
#include <utility>
class Puzzle
{
public:
	static void threeBottle() {
		using std::cout;
		using std::cin;
		using std::endl;

		const std::vector<int> bottleMax = { 8,5,3 };
		auto judgePoul = [](std::pair<int, size_t> from, std::pair<int, size_t> to) {
			if ((from.first + to.first) == to.second)//是否能将水壶完全倒满水
				return true;
			else if ((to.second - to.first) >= from.first)//是否能将水壶的水完全倒空
				return true;
			else
				return false;

		};
		auto Poul = [](std::vector<std::pair<int, size_t>> &bottles, size_t from, size_t to) {
			if((bottles[from].first + bottles[to].first) == bottles[to].second)
			{
				auto delta = bottles[to].second - bottles[to].first;
				bottles[from].first -= delta;
				bottles[to].second += delta;
			}
			else {
				bottles[to].first += bottles[from].first;
				bottles[from].first = 0;
			}

		};
		std::vector<std::vector<std::pair<int, size_t>>> memSteps;
		memSteps.push_back({ {8,8},{0,5},{0,3} });
		while (!(((*memSteps.rbegin())[0].first == 4) || ((*memSteps.rbegin())[1].first == 4) || ((*memSteps.rbegin())[2].first == 4))) {
			auto temp = *memSteps.rbegin();
			if (judgePoul((*memSteps.rbegin())[0], (*memSteps.rbegin())[1])) {
				Poul(temp, 0, 1);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			if (judgePoul((*memSteps.rbegin())[0], (*memSteps.rbegin())[2])) {
				Poul(temp, 0, 2);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			if (judgePoul((*memSteps.rbegin())[1], (*memSteps.rbegin())[2])) {
				Poul(temp, 1, 2);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			if (judgePoul((*memSteps.rbegin())[2], (*memSteps.rbegin())[1])) {
				Poul(temp, 2, 1);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			if (judgePoul((*memSteps.rbegin())[2], (*memSteps.rbegin())[0])) {
				Poul(temp, 2, 0);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			if (judgePoul((*memSteps.rbegin())[1], (*memSteps.rbegin())[0])) {
				Poul(temp, 1, 0);
				bool alreadyHave = false;
				for (auto i : memSteps) {
					size_t count = 0;
					for (auto j = 0; j < 3; ++j) {
						if (i[j].first == temp[j].first)
							++count;
					}
					if (count == 3) {
						alreadyHave = true;
					}
				}
				if (alreadyHave != true) {
					memSteps.push_back(temp);
				}
			}
			

			

		}
		for (auto i : memSteps) {
			for (auto j : i)
				cout << j.first << " ";
			cout << endl;
		}
	}
	static void plates() {
		using std::cout; 
		using std::cin; 
		using std::endl;
		using std::vector;
		int saucerNumber;
		//输入 数量为 2n 的一排碟子，n 黑 n 白交替放置
		cout << "请输入一个偶数用来表示碟子数: ";
		cin >> saucerNumber;
		cout << endl;
		//定义一个数组,用来存储数据
		vector<int> saucerArray(saucerNumber);
		int count = 0;  // 记录算法需要执行的换位次数。

		// 数组赋值------n 黑 n 白交替放置：黑、白、黑、白、黑、......
		for (int i = 0; i < saucerNumber - 1; i += 2) {
			saucerArray[i] = 1;
			saucerArray[i + 1] = 0;
		}
		//显示未排序之前的数组元素 
		cout << "排序之前的数组元素显示如下:" << endl;
		for (int i = 0; i < saucerNumber; i++) {
			cout << saucerArray[i] << " ";
		}
		cout << endl;
		//通过互换相邻碟子的位置来实现 黑碟子都放在右边，白碟子都放在左边

		//方法思路 (相邻元素为一组,然后分组操作元素互换) ---这个方法的时间复杂度不简便 
		int temp;
		for (int i = 1; i < saucerNumber / 2; i++) {   // saucerNumber个元素,分为 saucerNumber/2组,从第一组开始进行元素互换的操作,共saucerNumber/2-1 组 
			for (int j = i; j < saucerNumber - 1; j += 2) {  //从第i个元素开始配对, i和i+1 为一组 ,然后分组进行元素互换 
				temp = saucerArray[j];
				saucerArray[j] = saucerArray[j + 1];
				saucerArray[j + 1] = temp;
				count++;
			}
		}
		cout << "排序之后的数组元素显示如下:" << endl;
		for (int i = 0; i < saucerNumber; i++) {
			cout << saucerArray[i] << " ";
		}
		cout << endl;
		cout << "需要执行的换位次数为: " << count << "次!" << endl;
	}
	static void openedDoors() {
		using std::cout;
		using std::cin;
		using std::endl;
		using std::vector;
		int doorCount;
		//输入 门的总数
		cout << "请输入门的总数: ";
		cin >> doorCount;
		cout << endl;
		//定义一个数组,用来存储完全平方数
		vector<int> openedDoors;
		for (int i = 1; i * i <= doorCount; ++i) {
			openedDoors.push_back(i);
		}
		for (auto doorValue : openedDoors)
			cout << doorValue;
		cout << "以上为开启的门，其他为关闭的门";
	}
};

#endif // !PUZZLE_H

