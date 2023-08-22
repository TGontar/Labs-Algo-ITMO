//#include "iostream"
//#include "stdio.h"
//#include "math.h"
//
//using std::cin;
//using std::cout;
//
//double binary_search_doubles(double l, double r, int n, double A) {
//    while (true) {
//        double x1 = (r + l) / 2;
//        if (r - x1 < 0.000001) {
//            return r;
//        }
//        int flag = 0;
//        for (int i = 1; i <= n; i++) {
//            double xi = i * x1 - (i - 1) * A + i * (i - 1);
//            if (xi <= 0) {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag != 1) {
//            r = x1;
//        } else {
//            l = x1 + 0.00000001;
//        }
//    }
//}
//
//int main() {
//    int n;
//    double A;
//    cin >> n;
//    n = n - 1;
//    cin >> A;
//
//    double ansx1 = binary_search_doubles(0, A + 1, n, A);
//    double answer = (round((n*ansx1 - (n-1)*A + n*(n-1)) * 100.0)) / 100.0;
//    printf("%.2lf", answer);
//    return 0;
//}