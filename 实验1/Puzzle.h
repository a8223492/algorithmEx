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
		//���� ����Ϊ 2n ��һ�ŵ��ӣ�n �� n �׽������
		cout << "������һ��ż��������ʾ������: ";
		cin >> saucerNumber;
		cout << endl;
		//����һ������,�����洢����
		vector<int> saucerArray(saucerNumber);
		int count = 0;  // ��¼�㷨��Ҫִ�еĻ�λ������

		// ���鸳ֵ------n �� n �׽�����ã��ڡ��ס��ڡ��ס��ڡ�......
		for (int i = 0; i < saucerNumber - 1; i += 2) {
			saucerArray[i] = 1;
			saucerArray[i + 1] = 0;
		}
		//��ʾδ����֮ǰ������Ԫ�� 
		cout << "����֮ǰ������Ԫ����ʾ����:" << endl;
		for (int i = 0; i < saucerNumber; i++) {
			cout << saucerArray[i] << " ";
		}
		cout << endl;
		//ͨ���������ڵ��ӵ�λ����ʵ�� �ڵ��Ӷ������ұߣ��׵��Ӷ��������

		//����˼· (����Ԫ��Ϊһ��,Ȼ��������Ԫ�ػ���) ---���������ʱ�临�ӶȲ���� 
		int temp;
		for (int i = 1; i < saucerNumber / 2; i++) {   // saucerNumber��Ԫ��,��Ϊ saucerNumber/2��,�ӵ�һ�鿪ʼ����Ԫ�ػ����Ĳ���,��saucerNumber/2-1 �� 
			for (int j = i; j < saucerNumber - 1; j += 2) {  //�ӵ�i��Ԫ�ؿ�ʼ���, i��i+1 Ϊһ�� ,Ȼ��������Ԫ�ػ��� 
				temp = saucerArray[j];
				saucerArray[j] = saucerArray[j + 1];
				saucerArray[j + 1] = temp;
				count++;
			}
		}
		cout << "����֮�������Ԫ����ʾ����:" << endl;
		for (int i = 0; i < saucerNumber; i++) {
			cout << saucerArray[i] << " ";
		}
		cout << endl;
		cout << "��Ҫִ�еĻ�λ����Ϊ: " << count << "��!" << endl;
	}
	static void openedDoors() {
		using std::cout;
		using std::cin;
		using std::endl;
		using std::vector;
		int doorCount;
		//���� �ŵ�����
		cout << "�������ŵ�����: ";
		cin >> doorCount;
		cout << endl;
		//����һ������,�����洢��ȫƽ����
		vector<int> openedDoors;
		for (int i = 1; i * i <= doorCount; ++i) {
			openedDoors.push_back(i);
		}
		for (auto doorValue : openedDoors)
			cout << doorValue;
		cout << "����Ϊ�������ţ�����Ϊ�رյ���";
	}
};

#endif // !PUZZLE_H

