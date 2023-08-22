//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//void k_stat(int arr[], int l, int r, int k) {
//    int x = arr[(l + r) / 2];
//    int pivot = (l + r) / 2;
//    if (r - l == 1) {
//        cout << arr[k];
//        exit(0);
//    }
//    int m = l;
//    for (int i = l; i < r; i++) {
//        if (arr[i] < x) {
//            std::swap(arr[i], arr[m]);
//            m++;
//        }
//    }
//    if (k < m) {
//        k_stat(arr, l, m, k);
//    } else {
//        k_stat(arr, m, r, k-pivot-1);
//    }
//}
//
//
//
//int main() {
//    int n, k;
//    cin >> n;
//    cin >> k;
//
//    int A, B, C;
//    cin >> A;
//    cin >> B;
//    cin >> C;
//
//    int arr[n];
//    if (n==1) {
//        cin >> arr[0];
//        cin >> arr[0];
//        cout << arr[0];
//        exit(0);
//    }
//
//    for (int i = 0; i < 2; i++) {
//        cin >> arr[i];
//    }
//
//    for (int i = 2; i < n; i++) {
//        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
//    }
//
//
//    k_stat(arr, 0, n-1, k-1);
//
//
//    return 0;
//}