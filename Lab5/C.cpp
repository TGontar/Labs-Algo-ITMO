//#include "iostream"
//#include "string"
//
//using std::cin;
//using std::cout;
//
//
//void fillTree(int arr[][3], int k, int *number) {
//    if (k != 0) {
//        fillTree(arr, arr[k][1], number);
//    }
//    if (arr[k][0] == INT_MIN) {
//        arr[k][0] = *number;
//        *number += 1;
//    }
//    if (k != 0) {
//        fillTree(arr, arr[k][2], number);
//    }
//}
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
//        values[i][0] = INT_MIN;
//        cin >> values[i][1];
//        cin >> values[i][2];
//    }
//    int num = 1;
//
//    fillTree(values, 1, &num);
//
//    for (int i = 1; i <= n; i++) {
//        cout << values[i][0] << " ";
//    }
//
//    return 0;
//}