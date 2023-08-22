//#include "iostream"
//
//using std::cout;
//using std::cin;
//
////void quick_sort(int arr[], int l, int r) {
////    int i = l;
////    int j = r;
////    int x = arr[(l + r) / 2];
////    while (i <= j) {
////        while (arr[i] < x) {
////            i++;
////        }
////        while (arr[j] > x) {
////            j--;
////        }
////        if (i <= j) {
////            std::swap(arr[i], arr[j]);
////            i++;
////            j--;
////        }
////    }
////    if (l < j) {
////        quick_sort(arr, l, j);
////    }
////    if (i < r) {
////        quick_sort(arr, i, r);
////    }
////}
//
//void k_stat(int arr[], int l, int r, int k) {
//    int i = l;
//    int j = r;
//    int x = arr[(l + r) / 2];
//    int pivot = (l + r) / 2;
//    while (i <= j) {
//        while (arr[i] < x) {
//            i++;
//        }
//        while (arr[j] > x) {
//            j--;
//        }
//        if (i <= j) {
//            if (i == pivot) {
//                pivot = j;
//            } else if (j == pivot) {
//                pivot = i;
//            }
//            std::swap(arr[i], arr[j]);
//            i++;
//            j--;
//        }
//    }
//
//    if (pivot == k - 1) {
//        cout << arr[pivot];
//        return;
//    } else if (pivot > k - 1) {
//        k_stat(arr, l, pivot - 1, k);
//    } else if (pivot < k - 1) {
//        k_stat(arr, pivot + 1, r, k);
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    int k;
//    cin >> k;
//
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    k_stat(arr, 0, n-1, k);
//
//    return 0;
//}
