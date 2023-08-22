//#include "iostream"
//#include "string"
//
//using std::cin;
//using std::cout;
//
//bool isBinaryTree(int arr[][3], int k, int min, int max) {
//    if (k == 0) {
//        return true;
//    }
//    if (arr[k][0] <= min || arr[k][0] >= max) {
//        return false;
//    }
//    if (arr[k][1] != 0 && arr[k][2] == 0) {
//        return isBinaryTree(arr, arr[k][1], min, arr[k][0]);
//    } else if (arr[k][1] == 0 && arr[k][2] != 0) {
//        return isBinaryTree(arr, arr[k][2], arr[k][0], max);
//    } else {
//        return isBinaryTree(arr, arr[k][1], min, arr[k][0]) && isBinaryTree(arr, arr[k][2], arr[k][0], max);
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    if (n == 0) {
//        cout << "YES";
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
//    bool ans = isBinaryTree(values, 1, INT_MIN, INT_MAX);
//    if (ans) {
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
//
//    return 0;
//}