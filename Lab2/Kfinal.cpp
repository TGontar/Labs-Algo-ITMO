//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//int partition(int arr[], int l, int r) {
//    int i = l;
//    int j = r -1;
//    int x = arr[(l + r) / 2];
//
//    while (i <= j) {
//        while (arr[i] < x) {
//            i++;
//        }
//        while (arr[j] > x) {
//            j--;
//        }
//
//        if (i >= j) {
//            break;
//        }
//        std::swap(arr[i++], arr[j--]);
//    }
//    cout << x << "\n";
//    cout << j << "\n";
//    return j;
//}
//
//int k_stat(int arr[], int n, int k) {
//    int l = 0;
//    int r = n;
//    while (true) {
//        int mid = partition(arr, l, r);
//        if (mid == k) {
//            return arr[mid];
//        } else if (k < mid) {
//            r = mid;
//        } else {
//            l = mid + 1;
//        }
//    }
//}
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
//    for (int i = 0; i < 2; i++) {
//        cin >> arr[i];
//    }
//
//    for (int i = 2; i < n; i++) {
//        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//
//    int ans = k_stat(arr, n, k-1);
//    cout << ans;
//
//    return 0;
//}