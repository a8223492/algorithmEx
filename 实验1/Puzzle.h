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
			if ((from.first + to.first) == to.second)//�Ƿ��ܽ�ˮ����ȫ����ˮ
				return true;
			else if ((to.second - to.first) >= from.first)//�Ƿ��ܽ�ˮ����ˮ��ȫ����
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

