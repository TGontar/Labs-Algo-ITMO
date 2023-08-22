//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//void merge(int arr[], int left, int mid, int right) {
//    int it1 = 0;
//    int it2 = 0;
//    int result[right - left];
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
//        arr[left + i] = result[i];
//    }
//}
//
//void merge_sort(int arr[], int left, int right) {
//    if (left + 1 >= right) {
//        return;
//    }
//    int mid = (left + right) / 2;
//    merge_sort(arr, left, mid);
//    merge_sort(arr, mid, right);
//    merge(arr, left, mid, right);
//}
//
//int main() {
//    int n1;
//    cin >> n1;
//    int arr1[n1];
//    for (int i = 0; i < n1; i++) {
//        cin >> arr1[i];
//    }
//
//    int n2;
//    cin >> n2;
//    int arr2[n2];
//    for (int i = 0; i < n2; i++) {
//        cin >> arr2[i];
//    }
//
//    merge_sort(arr1, 0, n1);
//    merge_sort(arr2, 0, n2);
//
//    int k1 = 0;
//    for (int i = 0; i < (n1-1); i++) {
//        if (arr1[i] == arr1[i+1]) {
//            k1 += 1;
//        }
//    }
//    int final1[n1-k1];
//    final1[0] = arr1[0];
//    int j1 = 0;
//    for (int i = 0; i<(n1-1); i++) {
//        if (arr1[i] != arr1[i+1]) {
//            final1[j1+1] = arr1[i+1];
//        } else {
//            j1 -= 1;
//        }
//        j1 += 1;
//    }
//
//    int k2 = 0;
//    for (int i = 0; i < (n2-1); i++) {
//        if (arr2[i] == arr2[i+1]) {
//            k2 += 1;
//        }
//    }
//    int final2[n1-k1];
//    final2[0] = arr2[0];
//    int j2 = 0;
//    for (int i = 0; i<(n2-1); i++) {
//        if (arr2[i] != arr2[i+1]) {
//            final2[j2+1] = arr2[i+1];
//        } else {
//            j2 -= 1;
//        }
//        j2 += 1;
//    }
//
//    int flag = 0;
//    if (n1 - k1 == n2 - k2) {
//        for (int i = 0; i < (n1-k1); i++) {
//            if (final1[i] != final2[i]) {
//                flag = 1;
//                break;
//            }
//        }
//    } else {
//        flag = 1;
//    }
//    if (flag == 0) {
//        cout << "YES";
//    } else {
//        cout << "N0";
//    }
//
////    for (int i = 0; i < (n1-k1); i++) {
////        cout << final1[i] << " ";
////    }
////    cout << "\n";
////
////    for (int i = 0; i < (n2-k2); i++) {
////        cout << final2[i] << " ";
////    }
////    cout << "\n";
//
//    return 0;
//}