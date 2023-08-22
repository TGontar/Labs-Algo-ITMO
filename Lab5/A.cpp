//#include "iostream"
//#include "string"
//
//using std::cin;
//using std::cout;
//
//int findMax(int arr[][3], int k) {
//    if (k == 0) {
//        return 0;
//    } else {
//        int left = findMax(arr, arr[k][1]);
//        int right = findMax(arr, arr[k][2]);
//        int ans = (left > right) ? (left) : (right);
//        return 1 + ans;
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    if (n == 0) {
//        cout << 0;
//        exit(0);
//    }
//    int values[n + 1][3];
//    values[0][0] = 0;
//    values[0][1] = 0;
//    values[0][2] = 0;
//    for (int i = 1; i <= n; i++) {
//        cin >> values[i][0];
//        cin >> values[i][1];
//        cin >> values[i][2];
//    }
//    int ans = findMax(values, 1);
//    cout << ans;
//
//
//    return 0;
//}