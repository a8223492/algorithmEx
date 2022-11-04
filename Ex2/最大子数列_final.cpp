////采用分治法求解最大连续子序列和问题
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
//	//计算左半部分的最大子序列和
//	int maxLeftBorderSum = 0, leftBorderSum = 0;
//	for (int i = center; i >= left; i--)
//	{
//		leftBorderSum += a[i];
//		if (leftBorderSum > maxLeftBorderSum)
//			maxLeftBorderSum = leftBorderSum;
//	}
//	//计算右半部分的最大子序列和
//	int maxRightBorderSum = 0, rightBorderSum = 0;
//	for (int i = center + 1; i <= right; i++)
//	{
//		rightBorderSum += a[i];
//		if (rightBorderSum > maxRightBorderSum)
//			maxRightBorderSum = rightBorderSum;
//	}
//	//返回三者中的最大值
//	return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum);
//}
//int main()
//{
//	vector<int> a = { 5,-2,2,-2,-1,2,8,-7 };
//	cout << "数组为：";
//	for (auto i : a)
//		cout << i<<" ";
//	cout << endl;
//	cout << "最大连续子序列和为：" << MaxSubSum(a, 0, a.size() - 1);
//	return 0;
//}
