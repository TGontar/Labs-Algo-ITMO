//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//void merge(int arr[], int left, int mid, int right) {
//    int it1 = 0;
//    int it2 = 0;
//    int result[right-left];
//
//    while ((left + it1 < mid) && (mid + it2 < right)) {
//        if (arr[left + it1] < arr[mid + it2]) {
//            result[it1 + it2] = arr[left + it1];
//            it1++;
//        } else {
//            result[it1 + it2] = arr[mid + it2];
//            it2++;
//        }
//    }
//
//    while (left + it1 < mid) {
//        result[it1 + it2] = arr[left + it1];
//        it1++;
//    }
//
//    while (mid + it2 < right) {
//        result[it1 + it2] = arr[mid + it2];
//        it2++;
//    }
//
//    for (int i = 0; i < (it1 + it2); i++) {
//        arr[left +i] =result[i];
//    }
//}
//
//void merge_sort(int arr[], int left, int right) {
//    if (left+1 >= right) {
//        return;
//    }
//    int mid = (left + right) / 2;
//    merge_sort(arr, left, mid);
//    merge_sort(arr, mid, right);
//    merge(arr, left, mid, right);
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
//    merge_sort(arr, 0, n);
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}