//#include<vector>
//#include<float.h>
//#include<time.h>
//#include <chrono>
//#include<algorithm>
//#include<iostream>
//using std::vector;
//using Arr_2d = vector<vector<double>>;
//using Arr_1d = vector<double>;
//using std::cout;
//using std::endl;
// 
//double Dist(const Arr_1d& p1, const Arr_1d& p2)
//{
//    double y = p1[1] - p2[1];
//    double x = p1[0] - p2[0];
//	return sqrt(x * x + y * y);
//}
//Arr_2d MinDist(const Arr_2d & point) {
//    if (point.size() == 0 || point.size() == 1) {
//
//        return (Arr_2d{ {DBL_MAX}, {0,0}, {0,0} });
//    }
//	Arr_2d mindist = { {Dist(point[0], point[1])}, //mindist[0][0]是点1和点2的距离,
//                                {point[0][0],point[0][1]}, {point[1][0],point[1][1]} };
//    // mindist[1]是点1的xy坐标，mindist[2]是点2的xy坐标
//    for (int i = 0; i < point.size() - 1; i++) {
//        for (int j = i + 1; j < point.size(); j++) {
//            if (Dist(point[i], point[j]) < mindist[0][0]) {
//                mindist[0][0] = Dist(point[i], point[j]);
//                mindist[1] = point[i];
//                mindist[2] = point[j];
//            }
//        }
//    }
//    return mindist;
//}
//Arr_2d& SortArray(Arr_2d &point, int left, int right) {
//    if (left >= right) {
//        return point;
//    }
//    int i = left, j = right;
//    auto flag = point[left]; //把最低位作为标志位
//    while (i < j) {
//        while (i < j && point[j][0] >= flag[0]) {
//            j--;
//        }
//        while (i < j && point[i][0] <= flag[0]) {
//            i++;
//        }
//        auto temp = point[i];
//        point[i] = point[j];
//        point[j] = temp;
//    }
//    point[left] = point[i];
//    point[i] = flag;
//    SortArray(point, left, i - 1);
//    SortArray(point, i + 1, right);
//    return point;
//}
//Arr_2d SortArray(Arr_2d point) {
//    return SortArray(point, 0, point.size() - 1);
//}
//Arr_2d minDist_Divide(const Arr_2d& point, int left, int right) {
//    Arr_2d res(3);  // res[0][0]是最短距离,res[1]是点1的xy坐标，res[2]是点2的xy坐标
//	for (int i = 0; i < 3; i++)
//		res[i].resize(2);
//    double minDist = DBL_MAX;
//    if (left == right) {
//        return Arr_2d{ {minDist}, {0,0}, {0,0} }; //只有一个点或者没有点，返回max
//    }
//    if (left + 1 == right) {//只有两个2点直接求解
//        return Arr_2d{ {Dist(point[left], point[right])}, {point[left][0],point[left][1]}, {point[right][0],point[right][1]} };
//    }
//    if (left + 2 == right) { //三个点直接暴力求解
//        Arr_2d temp(3);
//		for (int i = 0; i < 3; i++)
//			temp[i].resize(2);
//        for (int i = 0; i < 3; i++) {
//            temp[i] = point[i + left];
//        }
//        return MinDist(temp);
//    }
//
//    int mid = (left + right) / 2;
//    auto leftMinDist = minDist_Divide(point, left, mid);
//    auto rightMinDist = minDist_Divide(point, mid, right);
//    res = min(leftMinDist, rightMinDist);
//    minDist = res[0][0];
//    //距离最近的两个点，一个位于左边区域，一个位于右边区域，x轴搜索范围[mid-minDist, mid+minDist]
//    double x1 = point[mid][0] - minDist;
//    double x2 = point[mid][0] + minDist;
//
//    int count = 0;
//    //        List<List<Double>> list = new ArrayList<>();
//    for (int i = left; i < right; i++) {
//        if (point[i][0] >= x1 && point[i][0] <= x2) {
//
//            count++;
//        }
//    }
//    Arr_2d temp(count);
//    for (int i = 0; i < count; i++)
//        temp[i].resize(2);
//    for (int i = 0; i < count; i++) {
//        temp[i] = point[i];
//    }
//    auto midMinDist = MinDist(temp);
//    auto min = [](Arr_2d& a, Arr_2d& b) {
//        if (a[0][0] < b[0][0]) {
//            return Arr_2d{ {a[0][0]}, a[1], a[2] };
//        }
//        else {
//            return Arr_2d{ {b[0][0]}, b[1], b[2] };
//        }
//    };
//    res = min(res, midMinDist);
//    return res;
//}
//Arr_2d minDist_Divide(Arr_2d point) {
//	auto SortPoint = SortArray(point);
//    return minDist_Divide(SortPoint, 0, SortPoint.size() - 1);
//}
//Arr_2d randomPoint(int length, int range) {
//    srand((int)time(0));
//    auto arr = Arr_2d(length);
//    for (int i = 0; i < length; i++)
//        arr[i].resize(2);
//    for (int i = 0; i < length - 1; ++i) {
//        arr[i][0] = rand() * range + 1;
//        arr[i][1] = rand() * range + 1;
//    }
//    return arr;
//}
//int main() {
//    //Arr_2d point = { {3,4},{6,6},{2,2},{33,1} };
//    int length = 10000;
//    auto point = randomPoint(length, 100);
//	auto point1 = point;
//    auto t1_start = std::chrono::steady_clock::now();
//    auto i = MinDist(point);
//    auto t1_end = std::chrono::steady_clock::now();
//
//    auto t2_start = std::chrono::steady_clock::now();
//    auto j = minDist_Divide(point);
//    auto t2_end = std::chrono::steady_clock::now();
//    cout << "暴力法求得的最优解为：" << i[0][0]<<endl;
//    cout << "分治法求得的最优解为：" << j[0][0] << endl;
//    cout << "暴力法的时间为：" << std::chrono::duration_cast<std::chrono::milliseconds>(t1_end - t1_start).count() << endl;
//    cout << "分治法的时间为：" << std::chrono::duration_cast<std::chrono::milliseconds>(t2_end - t2_start).count() << endl;
//    return 0;
//}