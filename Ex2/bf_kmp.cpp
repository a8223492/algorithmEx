//#include <string>
//using namespace std;
//int BF(string A, string B) {
//    int i = 0;
//    int j = 0;
//    while (i < A.length() && j < B.length()) {
//        if (A[i] == B[j]) {
//            i++;
//            j++;
//        }
//        else {
//            i = i - j + 1;
//            j = 0;
//        }
//    }
//    if (j >= B.length()) {
//        return i - B.length() + 1;
//    }
//    else {
//        return -1;
//    }
//}
//int KMP(string A, string B) {
//    int i = 0;
//    int j = 0;
//    int next[B.length()] = { 0 };
//    for (int j_1 = 2; j_1 < B.length(); j_1++) {
//        for (int num = j_1 - 1; num >= 1; num--) {
//            string head = B.substr(0, num);
//            string rear = B.substr(j_1 - num, num);
//            if (head == rear) {
//                next[j_1] = num;
//                break;
//            }
//        }
//    }
//    while (i < A.length() && j < B.length()) {
//        if (A[i] == B[j]) {
//            i++;
//            j++;
//        }
//        else {
//            if (j == 0) {
//                i++;
//            }
//            else {
//                j = next[j];
//            }
//        }
//    }
//    if (j >= B.length()) {
//        return i - j + 1;
//    }
//    else {
//        return -1;
//    }
//}
