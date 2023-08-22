//#include "iostream"
//
//using std::cin;
//using std::cout;
//
//void check_pyramid(int arr[], int n) {
//    int flag = 0;
//    for (int i = 1; i <= n; i++) {
//        if (2*i <= n) {
//            if (arr[i] > arr[2*i]) {
//                flag = 1;
//            }
//        }
//        if (2*i + 1 <= n) {
//            if (arr[i] > arr[2*i+1]) {
//                flag = 1;
//            }
//        }
//    }
//    if (flag == 0) {
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
//
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    int arr[n + 1];
//    arr[0] = 0;
//    for (int i = 1; i <= n; i++) {
//        cin >> arr[i];
//    }
//
//    check_pyramid(arr, n);
//
//    return 0;
//}