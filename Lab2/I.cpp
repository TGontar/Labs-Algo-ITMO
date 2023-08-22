//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//void quick_sort(int arr[], int l, int r) {
//        cout << l << " " << r << "\n";
//    for (int cnt = l; cnt <= r; cnt++) {
//        cout << arr[cnt] << " ";
//    } cout << "\n";
//    int i = l;
//    int j = r;
//    int x = arr[(l + r) / 2];
//    int pivot = (l + r) / 2;
//    int p = l-1;
//    int q = r+1;
//    while (i <= j) {
//        while (arr[i] < x) {
//            i++;
//        }
//        while (arr[j] > x) {
//            j--;
//        }
//        if (i <= j) {
//            std::swap(arr[i], arr[j]);
//            if (arr[i] == x and i != pivot) {
//                p++;
//                std::swap(arr[i], arr[p]);
//
//            }
//            i++;
//            if (arr[j] == x and j != pivot) {
//                q--;
//                std::swap(arr[j], arr[q]);
//            }
//            j--;
//        }
//    }
//
//    for (int cnt = l; cnt <= r; cnt++) {
//    cout << arr[cnt] << " ";
//    } cout << "\n";
//
//    j = i - 1;
//    i = i;
//    for (int k = l; k <= p; k++, j--) {
//        std::swap(arr[k], arr[j]);
//    }
//    for (int k = r; k >= q; k--, i++) {
//        std::swap(arr[k], arr[i]);
//    }
//    for (int cnt = l; cnt <= r; cnt++) {
//        cout << arr[cnt] << " ";
//    } cout << "\n";
////    cout << j << " " << i << "\n";
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