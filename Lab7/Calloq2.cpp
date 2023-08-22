//#include "iostream"
//#include "vector"
//
//using std::cin;
//using std::cout;
//
//
//int main() {
//    long long n;
//    cin >> n;
//
//    long long A[n][10];
//
//    A[0][0] = 0;
//    for (long long i = 1; i < 10; i++) {
//        A[0][i] = 1;
//    }
//
//    for (long long i = 1; i < n; i++) {
//        for (long long j = 0; j < 10; j++) {
//            A[i][j] = A[i - 1][j];
//            if (j > 0) {
//                A[i][j] += A[i-1][j-1];
//            }
//            if (j < 9) {
//                A[i][j] += A[i-1][j+1];
//            }
//        }
//    }
//
//    long long ans = 0;
//    for (long long i = 0; i < 10; i++) {
//        ans += A[n - 1][i];
//    }
//
//    cout << ans;
//
//    return 0;
//}
