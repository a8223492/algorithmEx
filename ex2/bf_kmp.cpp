///*
//����������------���η�
//*/
//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#include<float.h>
//#include<vector>
//
//using namespace std;
//
//int BF(const string& s, const string& p)
//{
//	int i = 0, j = 0;
//	while (i < s.size() && j < p.size())
//	{
//		if (s[i] == p[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			i = i - j + 1;
//			j = 0;
//		}
//	}
//	if (j == p.size())
//		return i - j;
//	else
//		return -1;
//}
//
//int kmp(string s, string p) {
//    size_t n = s.size(), m = p.size();
//    if (m == 0) return 0;
//    //�����ڱ�
//    s.insert(s.begin(), ' ');
//    p.insert(p.begin(), ' ');
//    vector<int> next(m + 1);
//    //Ԥ����next����
//    for (size_t i = 2, j = 0; i <= m; i++) {
//        while (j and p[i] != p[j + 1]) j = next[j];
//        if (p[i] == p[j + 1]) j++;
//        next[i] = j;
//    }
//    //ƥ�����
//    for (size_t i = 1, j = 0; i <= n; i++) {
//        while (j and s[i] != p[j + 1]) j = next[j];
//        if (s[i] == p[j + 1]) j++;
//        if (j == m) return i - m;
//    }
//    //δƥ�䵽�򷵻�-1
//    return -1;
//}
//int main()
//{
//
//    string s = "aChengYue";
//    string p = "Yue";
//    cout << "ĸ��Ϊ��" << s << endl;
//    cout << "�Ӵ�Ϊ��" << p << endl;
//    cout << "bf�㷨:" << endl;
//	cout << "�Ӵ���ĸ���е�λ��Ϊ��" << BF(s, p) << endl;
//	cout << "kmp�㷨:" << endl;
//	cout << "�Ӵ���ĸ���е�λ��Ϊ ��  " << kmp(s, p) << endl;
//    return 0;
//}