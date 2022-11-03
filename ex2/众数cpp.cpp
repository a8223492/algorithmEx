#include<vector>
#include<iostream>
using Arr = std::vector<int>;
Arr modeSum(Arr& arr, int left, int right) {
	Arr res(2); //res[0]��������res[1]���������ֵĴ���
	if (left >= right) {
		res[0] = arr[left];
		res[1] = 1;
		return res;
	}
    int t;
    int i = left;
    int j = right;
    int flag = arr[left]; //ѡȡ���λ��Ϊ��־λ���Ϳ������ƣ�
    // ����flag������ָ�ɱ�flagС�Ĳ��ֺͱ�flag��Ĳ��֣������flag������
    res[0] = flag;
    res[1] = 0;
    while (i < j) {
        while (arr[j] >= flag && i < j) {
            if (arr[j] == flag) res[1]++;
            j--;
        }
        while (arr[i] <= flag && i < j) {
            if (arr[i] == flag) res[1]++;
            i++;
        }
        if (i == left) res[1]++;   //��ֹjһֱ������i��ͬ�����ܽ���ڶ���whileѭ�������½����1
        t = arr[i];    //����i��j��Ӧ��Ԫ�أ����ǿ�������ѱ�flagС�Ķ�������ߣ���ķ��ұ�
        arr[i] = arr[j];
        arr[j] = t;
    }
    t = arr[i];   //��flag���뵽��Ӧ���ڵ�λ�ã�ʹ����������ߵĶ���flagС���ұߵı�flag��
    arr[i] = flag;
    arr[left] = t;
	auto leftRes = modeSum(arr, left, i - 1); //�ݹ�����ߵ�����������
	auto rightRes = modeSum(arr, i + 1, right); //�ݹ����ұߵ�����������
	
	if (leftRes[1] > rightRes[1]) {//�Ƚ��������ߵ�����������������������Ǹ�
		if (leftRes[1] > res[1]) {
			res[0] = leftRes[0];
			res[1] = leftRes[1];
		}
	}
	else {
		if (rightRes[1] > res[1]) {
			res[0] = rightRes[0];
			res[1] = rightRes[1];
		}
	}
	return res;
}
Arr modeSum(Arr &arr) {
	return modeSum(arr, 0, arr.size() - 1);
}

int main(){
	Arr arr = { 3,4,3,8,3,7,1,2,2,3 };
	auto res = modeSum(arr);
	std::cout <<"����Ϊ��" << res[0] << " ������Ϊ��" << res[1] << std::endl;
	return 0;
}