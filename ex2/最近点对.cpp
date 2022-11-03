////#include <iostream>  
////#include <ctime>
////#include <cmath>
////#include <algorithm>
////using namespace std;
////#define NO_DISTANCE 1000000
//////定义二维点Point
////typedef struct Point
////{
////	float x, y;     //二维点的横纵坐标，范围均为[-100,100]
////}Point;
//////用随机函数对点数组points中的二维点进行初始化
////void SetPoints(Point* points, int length){
////	srand(unsigned(time(NULL)));  //设置随机种子
////	for (int i = 0; i < length; i++)
////	{
////		points[i].x = (rand() % 20000) / 100 - 100;    //调整rand(),使得横纵坐标范围为[-100,100]
////		points[i].y = (rand() % 20000) / 100 - 100;
////	}
////}
//////平面上任意两点对之间的距离公式计算
////float Distance(Point a, Point b){
////	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
////}
//////自定义排序规则：依照结构体中的x成员变量升序排序
////bool CmpX(Point a, Point b){
////	return a.x < b.x;
////}
//////求出最近点对记录，并将两点记录再a、b中
////float ClosestPair(Point points[], int length, Point& a, Point& b){
////	float distance;        //记录集合points中最近两点距离
////	float d1, d2;           //记录分割后两个子集中各自最小点对距离
////	int i = 0, j = 0, k = 0;       //用于控制for循环的循环变量
////	Point a1, b1, a2, b2;     //保存分割后两个子集中最小点对
////	if (length < 2)return NO_DISTANCE;    //若子集长度小于2，定义为最大距离，表示不可达
////	if (length == 2) {	//若子集长度为2，直接求出最小点对
////		a = points[0];
////
////		b = points[1];
////
////		distance = Distance(points[0], points[1]);
////
////	}
////	else
////	{
////		Point* pts1 = new Point[length];     //开辟两个子集
////		Point* pts2 = new Point[length];
////		sort(points, points + length, CmpX);   //调用algorithm库中的sort函数对points进行排序，CmpX为自定义的排序规则
////		float mid = points[(length - 1) / 2].x;  //排完序后的中间下标值，即中位数
////		for (i = 0; i < length / 2; i++)
////			pts1[i] = points[i];
////		for (int j = 0, i = length / 2; i < length; i++)
////			pts2[j++] = points[i];
////		d1 = ClosestPair(pts1, length / 2, a1, b1);           //分治求解左半部分子集的最近点  
////		d2 = ClosestPair(pts2, length - length / 2, a2, b2);    //分治求解右半部分子集的最近点  
////		if (d1 < d2) { distance = d1; a = a1; b = b1; }
////		else { distance = d2; a = a2; b = b2; }
////
////
////
////		//求解跨分割线并在δ×2δ区间内的最近点对
////
////		Point* pts3 = new Point[length];
////
////		for (i = 0, k = 0; i < length; i++)
////
////			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];
////		for (i = 0; i < k; i++)
////			for (j = i + 1; j <= i + 7 && j < k; j++)    //只需与有序的领接的的7个点进行比较
////
////			{
////				if (Distance(pts3[i], pts3[j]) < distance)
////
////				{//如果跨分割线的两点距离小于已知最小距离，则记录该距离
////					distance = Distance(pts3[i], pts3[j]);
////					a = pts3[i];
////					b = pts3[j];
////				}
////			}
////	}
////	return distance;
////}
////int main(){
////	int N;      //随机生成的点对个数
////	Point a, b;
////	Point c, d;
////	float distance1;
////	cout << "请您输入二维点对个数：";
////	cin >> N;
////	if (N < 2)
////		cout << "请输入大于等于2的点个数！！" << endl;
////	else
////	{
////		cout << endl << "随机生成的" << N << "个二维点对如下：" << endl;
////		Point* points = new Point[N];
////		SetPoints(points, N);
////		for (int i = 0; i < N; i++)
////			cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
////		float temp = 0;          //穷举法找出最近点对
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
////					min_dis = temp;   //更新找到的最小距离
////					c = points[s];
////					d = points[t];
////
////				}
////			}
////		}
////		cout << "穷举法找出的最近点对是：" << "(" << c.x << "," << c.y << ")和" << "(" << d.x << "," << d.y << ")" << endl << "最近点对距离为：" << min_dis << '\n';
////
////		distance1 = ClosestPair(points, N, a, b);
////		cout << endl << endl << "按横坐标排序后的点对:" << endl;
////
////		for (int j = 0; j < N; j++)
////
////		{
////
////			cout << "(" << points[j].x << "," << points[j].y << ")" << endl;
////
////		}
////
////		cout << endl << "最近点对为：" << "(" << a.x << "," << a.y << ")和" << "(" << b.x << "," << b.y << ")" << endl << "最近点对距离为：" << distance1 << endl;
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
