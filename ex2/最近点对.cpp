////#include <iostream>  
////#include <ctime>
////#include <cmath>
////#include <algorithm>
////using namespace std;
////#define NO_DISTANCE 1000000
//////�����ά��Point
////typedef struct Point
////{
////	float x, y;     //��ά��ĺ������꣬��Χ��Ϊ[-100,100]
////}Point;
//////����������Ե�����points�еĶ�ά����г�ʼ��
////void SetPoints(Point* points, int length){
////	srand(unsigned(time(NULL)));  //�����������
////	for (int i = 0; i < length; i++)
////	{
////		points[i].x = (rand() % 20000) / 100 - 100;    //����rand(),ʹ�ú������귶ΧΪ[-100,100]
////		points[i].y = (rand() % 20000) / 100 - 100;
////	}
////}
//////ƽ�������������֮��ľ��빫ʽ����
////float Distance(Point a, Point b){
////	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
////}
//////�Զ�������������սṹ���е�x��Ա������������
////bool CmpX(Point a, Point b){
////	return a.x < b.x;
////}
//////��������Լ�¼�����������¼��a��b��
////float ClosestPair(Point points[], int length, Point& a, Point& b){
////	float distance;        //��¼����points������������
////	float d1, d2;           //��¼�ָ�������Ӽ��и�����С��Ծ���
////	int i = 0, j = 0, k = 0;       //���ڿ���forѭ����ѭ������
////	Point a1, b1, a2, b2;     //����ָ�������Ӽ�����С���
////	if (length < 2)return NO_DISTANCE;    //���Ӽ�����С��2������Ϊ�����룬��ʾ���ɴ�
////	if (length == 2) {	//���Ӽ�����Ϊ2��ֱ�������С���
////		a = points[0];
////
////		b = points[1];
////
////		distance = Distance(points[0], points[1]);
////
////	}
////	else
////	{
////		Point* pts1 = new Point[length];     //���������Ӽ�
////		Point* pts2 = new Point[length];
////		sort(points, points + length, CmpX);   //����algorithm���е�sort������points��������CmpXΪ�Զ�����������
////		float mid = points[(length - 1) / 2].x;  //���������м��±�ֵ������λ��
////		for (i = 0; i < length / 2; i++)
////			pts1[i] = points[i];
////		for (int j = 0, i = length / 2; i < length; i++)
////			pts2[j++] = points[i];
////		d1 = ClosestPair(pts1, length / 2, a1, b1);           //���������벿���Ӽ��������  
////		d2 = ClosestPair(pts2, length - length / 2, a2, b2);    //��������Ұ벿���Ӽ��������  
////		if (d1 < d2) { distance = d1; a = a1; b = b1; }
////		else { distance = d2; a = a2; b = b2; }
////
////
////
////		//����ָ��߲��ڦġ�2�������ڵ�������
////
////		Point* pts3 = new Point[length];
////
////		for (i = 0, k = 0; i < length; i++)
////
////			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];
////		for (i = 0; i < k; i++)
////			for (j = i + 1; j <= i + 7 && j < k; j++)    //ֻ�����������ӵĵ�7������бȽ�
////
////			{
////				if (Distance(pts3[i], pts3[j]) < distance)
////
////				{//�����ָ��ߵ��������С����֪��С���룬���¼�þ���
////					distance = Distance(pts3[i], pts3[j]);
////					a = pts3[i];
////					b = pts3[j];
////				}
////			}
////	}
////	return distance;
////}
////int main(){
////	int N;      //������ɵĵ�Ը���
////	Point a, b;
////	Point c, d;
////	float distance1;
////	cout << "���������ά��Ը�����";
////	cin >> N;
////	if (N < 2)
////		cout << "��������ڵ���2�ĵ��������" << endl;
////	else
////	{
////		cout << endl << "������ɵ�" << N << "����ά������£�" << endl;
////		Point* points = new Point[N];
////		SetPoints(points, N);
////		for (int i = 0; i < N; i++)
////			cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
////		float temp = 0;          //��ٷ��ҳ�������
////		float min_dis = 1000000000;
////		for (int s = 0; s < N - 1; s++)
////
////		{
////			for (int t = s + 1; t < N; t++)
////
////			{
////				temp = Distance(points[s], points[t]);
////
////				if (temp < min_dis)
////
////				{
////					min_dis = temp;   //�����ҵ�����С����
////					c = points[s];
////					d = points[t];
////
////				}
////			}
////		}
////		cout << "��ٷ��ҳ����������ǣ�" << "(" << c.x << "," << c.y << ")��" << "(" << d.x << "," << d.y << ")" << endl << "�����Ծ���Ϊ��" << min_dis << '\n';
////
////		distance1 = ClosestPair(points, N, a, b);
////		cout << endl << endl << "�������������ĵ��:" << endl;
////
////		for (int j = 0; j < N; j++)
////
////		{
////
////			cout << "(" << points[j].x << "," << points[j].y << ")" << endl;
////
////		}
////
////		cout << endl << "������Ϊ��" << "(" << a.x << "," << a.y << ")��" << "(" << b.x << "," << b.y << ")" << endl << "�����Ծ���Ϊ��" << distance1 << endl;
////
////	}
////
////	system("pause");
////}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//const int inf = 0x3f3f3f3f;
//const int maxn = 1e5 + 7;
//
//struct node {
//	double x, y;
//}a[maxn], b[maxn];
//struct ruleX {
//	bool operator()(const node& a, const node& b) {
//		return a.x < b.x;
//	}
//};
//struct ruleY {
//	bool operator()(const node& a, const node& b) {
//		return a.y < b.y;
//	}
//};
//double dis(node a, node b) {
//	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
//}
//double minDis(int l, int r) {
//	if (r - l + 1 == 2) return dis(a[l], a[r]);
//	if (r - l + 1 == 3) return min(dis(a[l], a[l + 1]), dis(a[l + 1], a[r]));
//	int mid = (l + r) >> 1;
//	
//	double d = min(minDis(l, mid), minDis(mid + 1, r));
//	int k = 0;
//	for (int i = l; i <= r; i++) {
//		if (fabs(a[i].x - a[mid].x) <= d) {
//			b[k++] = a[i];
//		}
//	}
//	sort(b, b + k, ruleY());
//	for (int i = 0; i < k; i++) {
//		for (int j = i + 1; j < k && j < i + 6; j++) {
//			d = min(d, dis(b[i], b[j]));
//		}
//	}
//	return d;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%lf %lf", &a[i].x, &a[i].y);
//	}
//	sort(a + 1, a + 1 + n, ruleX());
//	printf("%f\n", minDis(1, n));
//}
//
