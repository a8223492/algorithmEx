////���÷��η����������������к�����
//#include <iostream>	
//#include <vector>
//#include <algorithm>
//using namespace std;
//int MaxSubSum(const vector<int>& a, int left, int right)
//{
//
//	if (left == right)
//	{
//		if (a[left] > 0)
//			return a[left];
//		else
//			return 0;
//	}
//	int center = (left + right) / 2;
//	int maxLeftSum = MaxSubSum(a, left, center);
//	int maxRightSum = MaxSubSum(a, center + 1, right);
//	//������벿�ֵ���������к�
//	int maxLeftBorderSum = 0, leftBorderSum = 0;
//	for (int i = center; i >= left; i--)
//	{
//		leftBorderSum += a[i];
//		if (leftBorderSum > maxLeftBorderSum)
//			maxLeftBorderSum = leftBorderSum;
//	}
//	//�����Ұ벿�ֵ���������к�
//	int maxRightBorderSum = 0, rightBorderSum = 0;
//	for (int i = center + 1; i <= right; i++)
//	{
//		rightBorderSum += a[i];
//		if (rightBorderSum > maxRightBorderSum)
//			maxRightBorderSum = rightBorderSum;
//	}
//	//���������е����ֵ
//	return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum);
//}
//int main()
//{
//	vector<int> a = { 5,-2,2,-2,-1,2,8,-7 };
//	cout << "����Ϊ��";
//	for (auto i : a)
//		cout << i<<" ";
//	cout << endl;
//	cout << "������������к�Ϊ��" << MaxSubSum(a, 0, a.size() - 1);
//	return 0;
//}
