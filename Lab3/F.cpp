//#include "iostream"
//#include "vector"
//
//using std::cin;
//using std::cout;
//
//int binary_search_left(int arr[], int l, int r, int k) {
//    while (true) {
//        int mid = (l + r) / 2;
//        if (k <= arr[mid]) {
//            r = mid;
//        } else {
//            l = mid + 1;
//        }
//        if (r - l < 2) {
//            if (arr[l] == k) {
//                return l + 1;
//            } else if (arr[r] == k) {
//                return r + 1;
//            } else {
//                return -1;
//            }
//        }
//    }
//}
//
//int binary_search_right(int arr[], int l, int r, int k) {
//    while (true) {
//        int mid = (l + r) / 2;
//        if (k >= arr[mid]) {
//            l = mid;
//        } else {
//            r = mid - 1;
//        }
//        if (r - l < 2) {
//            if (arr[r] == k) {
//                return r + 1;
//            } else if (arr[l] == k) {
//                return l + 1;
//            } else {
//                return -1;
//            }
//        }
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    int m;
//    cin >> m;
//    int requests[m];
//    for (int i = 0; i < m; i++) {
//        cin >> requests[i];
//    }
//
//    int ans[m][2];
//    for (int i = 0; i < m; i++) {
//        ans[i][0] = binary_search_left(arr, 0, n, requests[i]);
//        ans[i][1] = binary_search_right(arr, 0, n, requests[i]);
//    }
//
//    for (int i = 0; i < m; i++) {
//        cout << ans[i][0] << " " << ans[i][1] << '\n';
//    }
//
//
//    return 0;
//}
