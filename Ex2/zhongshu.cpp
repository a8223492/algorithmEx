//#include<stdio.h>
//#include<stdlib.h> // standard_library
//int* GetMode(int* data, int data_lenth, int low, int high) {
//    int* p = (int*)malloc(sizeof(int) * 2);
//    p[0] = data[low];
//    p[1] = 1;
//    if (low < high) {
//        int pkey = data[low], t;
//        int low2 = low, high2 = high;
//        while (low2 < high2) {
//            while (low2 < high2 && data[high2] >= pkey) {
//                if (data[high2] == pkey)p[1]++; // 记录基准数的众数
//                high2--;
//            }
//            data[low2] = data[high2];
//            while (low2 < high2 && data[low2] <= pkey) {
//                if (data[low2] == pkey)p[1]++; // 记录基准数的众数
//                low2++;
//            }
//            data[high2] = data[low2];
//        }
//        data[low2] = pkey;
//        int ploc = low2;
//        int* p2 = GetMode(data, data_lenth, low, ploc - 1); //左部分众数 
//        int* p3 = GetMode(data, data_lenth, ploc + 1, high);  //右部分众数 
//        if (p2[1] > p3[1]);
//        else p2 = p3;
//        if (p[1] > p2[1]);
//        else p = p2;
//    }
//    return p;
//}
//int main() {
//    int n; printf("n="); scanf("%d", &n);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    int* p = GetMode(arr, n, 0, n - 1);
//    printf("------\n%d\n%d\n", p[0], p[1]);
//
//    return 0;
//}
