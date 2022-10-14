#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include<iostream>
#include<vector>
#include <utility>
class Puzzle
{
	typedef std::pair<size_t, size_t> Bottle;//抽象了个瓶子，Bottle.first表示水壶当前有多少水，second表示最大水量
	typedef std::vector<Bottle> Bottles;

public:
	static void threeBottle() {
		using std::cout;
		using std::cin;
		using std::endl;

		const std::vector<size_t> bottleMax = { 8,5,3 };
		auto judgePoul = [](const Bottle from,const Bottle to){//检测能不能倒
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
		std::vector<Bottles> memSteps;//记录状态
		auto judgeAlreadyHave = [&memSteps] (const Bottles &bottles){//检测是否在记录中出现过
			for(auto bm : memSteps)
				if(bottles[0].first == bm[0].first && bottles[1].first == bm[1].first && bottles[2].first == bm[2]. first)
					return true;
			return false;
		};
		memSteps.push_back({ {8,8},{0,5},{0,3} });
		while (((*memSteps.rbegin())[0].first != 4) && ((*memSteps.rbegin())[1].first != 4) && ((*memSteps.rbegin())[2].first != 4)) {
			auto tempBottles = *memSteps.rbegin();//拷贝最后的状态，取值
			//下面是六个if，分别代表六种倒水情况，A33嘛。虽然代码多，但容易想出来啊，不寒掺
			if (judgePoul(tempBottles[0], tempBottles[1])) {
				Poul(tempBottles, 0, 1);
				bool alreadyHave = judgeAlreadyHave(tempBottles);
				if (alreadyHave != true) {
					memSteps.push_back(tempBottles);
					for(auto tempBottle :tempBottles)
						cout<<tempBottle.first<<" ";
					cout<<endl;

				} 
					tempBottles = *memSteps.rbegin();//这样倒已经存在，则还原之前的拷贝


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
				Poul(tempBottles, 1, 2);
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
	static void doors() {
		using std::cout;
		using std::cin;
		using std::endl;
		using std::vector;
		using DoorState = bool;
		using DoorNumber = size_t;
		const DoorState OPEN = true;
		const DoorState CLOSE = false;
		DoorNumber doorCount = 0;
		cout << "请输入门的个数：" << endl;
		cin >> doorCount;
		vector<DoorState> doorStates(doorCount + 1,CLOSE);
		vector<DoorNumber> openedDoors;
		vector<DoorNumber> closedDoors;
		for (DoorNumber i = 1; i <= doorCount; ++i)//i表示当前走过的门
		{
			for (DoorNumber j = 1; j <= doorCount; ++j)//找倍数
			{
				if (j % i == 0)//当j取余i等于0时，代表j是i的倍数
					doorStates[j] = (!doorStates[j]);//改变门的状态
			}
		}
		for (DoorNumber i = 1; i <= doorCount; i++)
		{
			if (doorStates[i] == CLOSE)
				closedDoors.push_back(i);
			else
				openedDoors.push_back(i);
		}
		cout << "开着的门有：" << endl;
		for (auto i : openedDoors)
			cout << i << " ";
		cout << endl;
		cout << "关着的门有：" << endl;
		for (auto i : closedDoors)
			cout << i << " ";
		cout << endl;
	}
	static void openedDoors() {
		using std::cout;
		using std::cin;
		using std::endl;
		using std::vector;
		using DoorNunber = size_t;
		DoorNunber doorCount;
		//输入 门的总数
		cout << "请输入门的总数: ";
		cin >> doorCount;
		cout << endl;
		//定义一个数组,用来存储完全平方数
		for (DoorNunber i = 1; i * i <= doorCount; ++i)
			cout << i * i << " ";
		cout << endl;
		cout << "以上为开启的门，其他为关闭的门" << endl;
	}
};

#endif // !PUZZLE_H

