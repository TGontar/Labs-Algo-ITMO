//#include "iostream"
//
//using std::cin;
//using std::cout;
//
//int binary_search(int arr[], int l, int r, int k) {
//    while (true) {
//        int mid = (l + r) / 2;
//        if (l > r) {
//            return -1;
//        } else if (arr[mid] == k) {
//            return mid + 1;
//        } else if (arr[mid] > k) {
//            r = mid - 1;
//        } else {
//            l = mid + 1;
//        }
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    int k;
//    cin >> k;
//
//    int ans = binary_search(arr, 0, n - 1, k);
//    cout << ans;
//
//
//    return 0;
//}