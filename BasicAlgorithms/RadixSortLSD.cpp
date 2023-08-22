//#include "iostream"
//#include "cmath"
//
//using std::cin;
//using std::cout;
//
//int digit(int n, int k) {
//    int a = pow(10, k);
//    int b = pow(10, k-1);
//    int ans = (n % a) / b;
//    return ans;
//}
//
//
//int* RadixSort(int arr[], int n, int m) {
//    for (int i = 1; i <= m; i++) {
//        int C[10];
//        int *B = new int[n];
//        for (int j = 0; j < 10; j++) {
//            C[j] = 0;
//        }
//        for (int j = 0; j < n; j++) {
//            int d = digit(arr[j], i);
//            C[d] += 1;
//        }
//        int cnt = 0;
//        for (int j = 0; j < 10; j++) {
//            int tmp = C[j];
//            C[j] = cnt;
//            cnt += tmp;
//        }
//        for (int j = 0; j < n; j++) {
//            int d = digit(arr[j], i);
//            B[C[d]] = arr[j];
//            C[d] += 1;
//        }
//        arr = B;
//    }
//    return arr;
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    int *arr = new int[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    int *ans = RadixSort(arr, n, 2);
//
//    for (int i = 0; i < n; i++) {
//        cout << ans[i] << " ";
//    }
//
//    return 0;
//}