//#include "iostream"
//
//using std::cin;
//using std::cout;
//using std::max;
//
//int main() {
//    int S;
//    int N;
//    cin >> S;
//    cin >> N;
//    int elems[N];
//    for (int i = 0; i < N; i++) {
//        cin >> elems[i];
//    }
//
//    int zoloto[N + 1][S + 1];
//
//    for (int i = 0; i <= S; i++) {
//        zoloto[0][i] = 0;
//    }
//
//    for (int i = 0; i <= N; i++) {
//        zoloto[i][0] = 0;
//    }
//
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= S; j++) {
//            if (j >= elems[i - 1]) {
//                zoloto[i][j] = max(zoloto[i - 1][j], zoloto[i - 1][j - elems[i - 1]] + elems[i - 1]);
//            } else {
//                zoloto[i][j] = zoloto[i - 1][j];
//            }
//        }
//    }
//
//    cout << zoloto[N][S];
//
//    return 0;
//}