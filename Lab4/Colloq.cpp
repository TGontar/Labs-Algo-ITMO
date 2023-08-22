//#include "iostream"
//
//using std::cin;
//using std::cout;
//
//int main() {
//    int n;
//    cin >> n;
//    int m;
//    cin >> m;
//    long long x[n + 1];
//    long long y[n + 1];
//    x[0] = 0;
//    y[0] = 0;
//    for (int i = 1; i <= n; i++) {
//        char let;
//        cin >> let;
//        int diff;
//        cin >> diff;
//        if (let == 'R') {
//            x[i] = diff;
//            y[i] = 0;
//        } else if (let == 'L') {
//            x[i] = -1 * diff;
//            y[i] = 0;
//        } else if (let == 'U') {
//            x[i] = 0;
//            y[i] = diff;
//        } else if (let == 'D') {
//            x[i] = 0;
//            y[i] = -diff;
//        }
//    }
//    int tasks[m][2];
//    for (int i = 0; i < m; i++) {
//        cin >> tasks[i][0];
//        cin >> tasks[i][1];
//    }
//
//
//
//    for (int i = 2; i <= n; i++) {
//        x[i] = x[i] + x[i-1];
//        y[i] = y[i] + y[i-1];
//    }
//
//
//    long long ans[m][2];
//    for (int i = 0; i < m; i++) {
//        long long xans;
//        xans = x[tasks[i][1]] - x[tasks[i][0]];
//        if (xans >= 0) {
//            ans[i][0] = xans;
//        } else {
//            ans[i][0] = -1*xans;
//        }
//        long long yans;
//        yans = y[tasks[i][1]] - y[tasks[i][0]];
//        if (yans >= 0) {
//            ans[i][1] = yans;
//        } else {
//            ans[i][1] = -1*yans;
//        }
//    }
//
//    for (int i = 0; i < m; i++) {
//        cout << ans[i][0] << " " << ans[i][1] << "\n";
//    }
//
//    return 0;
//}
//
