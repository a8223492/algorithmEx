//#include<stdio.h>
//int num[10] = { 34,-20,30,-50,60,-20,30,41,-30,-10 };
////int num[6] = {-2,11,-4,13,-5,-2}; 
//int max3(int a, int b, int c) { //�����ߵ����ֵ
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
//	if (left == right) {  //ֻ��һ��Ԫ�ص����
//		if (a[left] >= 0)
//			return a[left];
//		else
//			return 0;
//	}
//	int mid = (left + right) / 2; //ȡ�м�λ��
//
//	maxLeftSum = maxSubSum(a, left, mid); //����ߵ�������к�
//	maxRightSum = maxSubSum(a, mid + 1, right); //���ұߵ�������к�
//
//	maxLeftBorderSum = 0;
//	leftBorderSum = 0;
//	maxRightBorderSum = 0;
//	rightBorderSum = 0;
//	//�������������������a���в���ռ���������������
//	for (i = mid; i >= left; i--) { //��mid����ߵ�maxLeftBorderSum
//		leftBorderSum += a[i];
//		if (maxLeftBorderSum < leftBorderSum)
//			maxLeftBorderSum = leftBorderSum;
//	}
//
//	for (j = mid + 1; j <= right; j++) { //��mid���ұߵ�maxRightBorderSum
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