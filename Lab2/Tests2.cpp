////#include "iostream"
////#include "vector"
////#include "algorithm"
////
////using std::cout;
////using std::cin;
////
////void k_stat(int arr[], int l, int r, int k) {
////    int i = l;
////    int j = r;
////    int x = arr[(l + r) / 2];
////    int pivot = (l + r) / 2;
////    while (i <= j) {
////        while (arr[i] < x) {
////            i++;
////        }
////        while (arr[j] > x) {
////            j--;
////        }
////        if (i <= j) {
////            if (i == pivot) {
////                pivot = j;
////            } else if (j == pivot) {
////                pivot = i;
////            }
////            std::swap(arr[i], arr[j]);
////            i++;
////            j--;
////        }
////    }
////    if (pivot == k - 1) {
////        cout << arr[pivot];
////        exit(0);
////    } else if (pivot > k - 1) {
////        k_stat(arr, l, pivot-1, k);
////    } else if (pivot < k - 1) {
////        k_stat(arr, pivot+1, r, k - pivot - 1);
////    }
////}
////
////int main() {
////    int n, k;
////    cin >> n;
////    cin >> k;
////
////    int A, B, C;
////    cin >> A;
////    cin >> B;
////    cin >> C;
////
////    std::vector <int> arr;
////    for (int i = 0; i < 2; i++) {
////        int k;
////        cin >> k;
////        arr.push_back(k);
////    }
////
////    for (int i = 2; i < n; i++) {
////        arr.push_back(A * arr[i - 2] + B * arr[i - 1] + C);
////    }
////
//////    k_stat(arr, 0, n-1, k);
////    for (int i =0; i < arr.size(); i++) {
////        cout << arr[i] << " ";
////    }
////    cout << "\n";
////
////    int ans = std::nth_element()
////
////    return 0;
////}
////#include "iostream"
////
////int main() {
////    int l = 0;
////    int r = 4;
////    int arr[5] = {2, 3, 1, 4, 5};
////    int x = arr[(l + r) / 2];
////    int m = l;
////    for (int i = l; i < r; i++) {
////        if (arr[i] < x) {
////            std::swap(arr[i], arr[m]);
////            std::cout << arr[i] << " " << arr[m] << "\n";
////            m++;
////        }
////    }
////    for (int i = 0; i <= r; i++) {
////        std::cout << arr[i] << " ";
////    }
////    std::cout << "\n" << m;
////
////}
//#include "iostream"
//using namespace std;
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
//    quick_sort(arr, 0, n-1);
//
//    cout << arr[k-1];
//
//    return 0;
//}