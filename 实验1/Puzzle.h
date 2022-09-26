#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include<iostream>
#include<vector>
#include <utility>
class Puzzle
{
	typedef std::vector<std::pair<size_t,size_t>> Bottles;
	typedef std::pair<size_t,size_t> Bottle;
public:
	static void threeBottle(){
		using std::cout;
		using std::cin;
		using std::endl;
	}
	static void threeBawottle() {
		using std::cout;
		using std::cin;
		using std::endl;

		const std::vector<size_t> bottleMax = { 8,5,3 };
		auto judgePoul = [](const Bottle from,const Bottle to) {
			if(from.first==0)
				return false;
			if(to.first == to.second)
				return false;
			else
				return true;

		};
		auto Poul = [](Bottles &bottles, size_t from, size_t to) {
			if((bottles[from].first + bottles[to].first) > bottles[to].second)
			{
				auto delta = bottles[to].second - bottles[to].first;
				bottles[from].first -= delta;
				bottles[to].first += delta;
			}
			else {
				bottles[to].first += bottles[from].first;
				bottles[from].first = 0;
			}

		};
		std::vector<Bottles> memSteps;
		auto judgeAlreadyHave = [&memSteps] (const Bottles &bottles){
			for(auto bm : memSteps)
				if(bottles[0].first == bm[0].first && bottles[1].first == bm[1].first && bottles[2].first == bm[2]. first)
					return true;
			return false;
		};
		memSteps.push_back({ {8,8},{0,5},{0,3} });
		while (((*memSteps.rbegin())[0].first != 4) && ((*memSteps.rbegin())[1].first != 4) && ((*memSteps.rbegin())[2].first != 4)) {
			auto tempBottles = *memSteps.rbegin();
			if (judgePoul(tempBottles[0], tempBottles[1])) {
				Poul(tempBottles, 0, 1);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();


			}
			if (judgePoul(tempBottles[0], tempBottles[2])) {
				Poul(tempBottles, 0, 2);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();

			}
			
			if (judgePoul(tempBottles[1], tempBottles[0])) {
				Poul(tempBottles, 1, 0);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();

			}
			
			if (judgePoul(tempBottles[2], tempBottles[0])) {
				Poul(tempBottles, 2, 0);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();

			}
			
			if (judgePoul(tempBottles[2], tempBottles[1])) {
				Poul(tempBottles, 2, 1);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();

			}
			
			if (judgePoul(tempBottles[1], tempBottles[2])) {
				Poul(tempBottles, 1, 1);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();

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

