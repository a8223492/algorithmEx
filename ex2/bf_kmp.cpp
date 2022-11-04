// 模式匹配 BF算法 
#include<iostream> 
#include<cstring> 
using namespace std;

int BF(char S[], char T[])
{
    //	start:T在S开始匹配的位置，i,j分别是S和T匹配的下标 
    int i = 0, j = 0, start = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j]) { i++;   j++; }  // 匹配成功，则下标后移
        else { start++;  i = start;  j = 0; } // 匹配不成功，则回溯到start位置 
    }
    if (T[j] == '\0') return start + 1;   // 直到 T匹配完成，返回本趟开始匹配的位置 
    else return 0;
}
//  KMP算法—先算出next[]数组 
int* getNext(char T[])
{
    int T_len = strlen(T);
    int* next = new int[T_len];    // 声明next数组
    int i = 0;    // T的下标
    int j = -1;
    next[0] = -1;

    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j]) { next[++i] = ++j; }
        else  j = next[j];
    }
    return next;
}
//  KMP算法
int KMP(char S[], char T[], int next[])
{
    //	start:T在S开始匹配的位置，i,j分别是S和T匹配的下标 
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j]) { i++;   j++; }  // 匹配成功，则下标后移
        else if (j == -1) { i++; j++; }
        else { j = next[j]; } // 匹配不成功，则回溯到start位置 
    }
    if (T[j] == '\0') return i - j;   // 直到 T匹配完成，返回本趟开始匹配的位置 
    else return 0;
}

int main() {
    char S[] = "ababaababcb";
    char T[] = "ababc";
    cout << "匹配开始！" << endl; cout << endl;

    //	BF算法 
    //	int n = BF(S,T);

    //  KMP算法—先算出next[]数组 
    int* next = getNext(T);
    cout << "next[] = ";
    for (int i = 0; i < strlen(T); i++) {
        cout << next[i] << " ";
    }cout << endl; cout << endl;
    //	匹配开始的位置 n
    int n = KMP(S, T, next);

    if (n > 0) {
        cout << "“" << S << "” 和 “" << T << "” 匹配成功，匹配开始的位置是：" << n << endl;
    }
    else cout << "匹配失败！" << endl;

    return 0;
}
