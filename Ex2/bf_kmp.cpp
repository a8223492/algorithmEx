// ģʽƥ�� BF�㷨 
#include<iostream> 
#include<cstring> 
using namespace std;

int BF(char S[], char T[])
{
    //	start:T��S��ʼƥ���λ�ã�i,j�ֱ���S��Tƥ����±� 
    int i = 0, j = 0, start = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j]) { i++;   j++; }  // ƥ��ɹ������±����
        else { start++;  i = start;  j = 0; } // ƥ�䲻�ɹ�������ݵ�startλ�� 
    }
    if (T[j] == '\0') return start + 1;   // ֱ�� Tƥ����ɣ����ر��˿�ʼƥ���λ�� 
    else return 0;
}
//  KMP�㷨�������next[]���� 
int* getNext(char T[])
{
    int T_len = strlen(T);
    int* next = new int[T_len];    // ����next����
    int i = 0;    // T���±�
    int j = -1;
    next[0] = -1;

    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j]) { next[++i] = ++j; }
        else  j = next[j];
    }
    return next;
}
//  KMP�㷨
int KMP(char S[], char T[], int next[])
{
    //	start:T��S��ʼƥ���λ�ã�i,j�ֱ���S��Tƥ����±� 
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j]) { i++;   j++; }  // ƥ��ɹ������±����
        else if (j == -1) { i++; j++; }
        else { j = next[j]; } // ƥ�䲻�ɹ�������ݵ�startλ�� 
    }
    if (T[j] == '\0') return i - j;   // ֱ�� Tƥ����ɣ����ر��˿�ʼƥ���λ�� 
    else return 0;
}

int main() {
    char S[] = "ababaababcb";
    char T[] = "ababc";
    cout << "ƥ�俪ʼ��" << endl; cout << endl;

    //	BF�㷨 
    //	int n = BF(S,T);

    //  KMP�㷨�������next[]���� 
    int* next = getNext(T);
    cout << "next[] = ";
    for (int i = 0; i < strlen(T); i++) {
        cout << next[i] << " ";
    }cout << endl; cout << endl;
    //	ƥ�俪ʼ��λ�� n
    int n = KMP(S, T, next);

    if (n > 0) {
        cout << "��" << S << "�� �� ��" << T << "�� ƥ��ɹ���ƥ�俪ʼ��λ���ǣ�" << n << endl;
    }
    else cout << "ƥ��ʧ�ܣ�" << endl;

    return 0;
}
