//#include<stdio.h>
//int num[10] = { 34,-20,30,-50,60,-20,30,41,-30,-10 };
////int num[6] = {-2,11,-4,13,-5,-2}; 
//int max3(int a, int b, int c) { //求三者的最大值
//	if (a < b)
//		a = b;
//	if (a < c)
//		a = c;
//	return a;
//}
//int maxSubSum(int a[], int left, int right) {
//	int i, j;
//	int maxLeftSum, maxRightSum;
//	int maxLeftBorderSum, leftBorderSum;
//	int maxRightBorderSum, rightBorderSum;
//	if (left == right) {  //只有一个元素的情况
//		if (a[left] >= 0)
//			return a[left];
//		else
//			return 0;
//	}
//	int mid = (left + right) / 2; //取中间位置
//
//	maxLeftSum = maxSubSum(a, left, mid); //求左边的最大序列和
//	maxRightSum = maxSubSum(a, mid + 1, right); //求右边的最大序列和
//
//	maxLeftBorderSum = 0;
//	leftBorderSum = 0;
//	maxRightBorderSum = 0;
//	rightBorderSum = 0;
//	//最大连续子序列在序列a的中部而占据左右两部分情况
//	for (i = mid; i >= left; i--) { //求mid到左边的maxLeftBorderSum
//		leftBorderSum += a[i];
//		if (maxLeftBorderSum < leftBorderSum)
//			maxLeftBorderSum = leftBorderSum;
//	}
//
//	for (j = mid + 1; j <= right; j++) { //求mid到右边的maxRightBorderSum
//		rightBorderSum += a[j];
//		if (maxRightBorderSum < rightBorderSum)
//			maxRightBorderSum = rightBorderSum;
//	}
//	return max3(maxRightBorderSum, maxLeftBorderSum, maxLeftBorderSum + maxRightBorderSum);
//}
//
//int main() {
//	printf("maxSubSum= %d\n", maxSubSum(num, 0, 9));
//	return 0;
//}