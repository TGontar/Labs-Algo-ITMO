//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//void quick_sort(int arr[], int l, int r) {
//    int i = l;
//    int j = r;
//    int x = arr[(l + r) / 2];
//    while (i <= j) {
//        while (arr[i] < x) {
//            i++;
//        }
//        while (arr[j] > x) {
//            j--;
//        }
//        if (i <= j) {
//            std::swap(arr[i], arr[j]);
//            i++;
//            j--;
//        }
//    }
//    if (l < j) {
//        quick_sort(arr, l, j);
//    }
//    if (i < r) {
//        quick_sort(arr, i, r);
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    quick_sort(arr, 0, n - 1);
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}