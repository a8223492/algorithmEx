#include<vector>
#include<iostream>
using Arr = std::vector<int>;
Arr modeSum(Arr& arr, int left, int right) {
	Arr res(2); //res[0]存众数，res[1]存众数出现的次数
	if (left >= right) {
		res[0] = arr[left];
		res[1] = 1;
		return res;
	}
    int t;
    int i = left;
    int j = right;
    int flag = arr[left]; //选取最低位作为标志位，和快排类似，
    // 根据flag将数组分割成比flag小的部分和比flag大的部分，并求出flag的重数
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
        if (i == left) res[1]++;   //防止j一直减到和i相同，不能进入第二个while循环，导致结果少1
        t = arr[i];    //交换i和j对应的元素，就是快排里面把比flag小的都放他左边，大的放右边
        arr[i] = arr[j];
        arr[j] = t;
    }
    t = arr[i];   //将flag插入到他应该在的位置，使数组满足左边的都比flag小，右边的比flag大
    arr[i] = flag;
    arr[left] = t;
	auto leftRes = modeSum(arr, left, i - 1); //递归求左边的众数与重数
	auto rightRes = modeSum(arr, i + 1, right); //递归求右边的众数与重数
	
	if (leftRes[1] > rightRes[1]) {//比较左右两边的众数重数，返回重数大的那个
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
	std::cout <<"众数为：" << res[0] << " ，重数为：" << res[1] << std::endl;
	return 0;
}