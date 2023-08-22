//#include "iostream"
//
//using std::cin;
//using std::cout;
//using std::endl;
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
//    int n, m;
//    cin >> n;
//    cin >> m;
//
//    int plots[n * m];
//    for (int i = 0; i < (n * m); i++) {
//        cin >> plots[i];
//    }
//
//    int k;
//    cin >> k;
//
//    int ppl[k];
//    for (int i = 0; i < k; i++) {
//        cin >> ppl[i];
//    }
//
//    merge_sort(plots, 0, n*m);
//    merge_sort(ppl, 0, k);
//    int ans = 0;
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < (n * m); j++) {
//            if (ppl[i] <= plots[j]) {
//                ppl[i] = 2111111111;
//                plots[j] = 0;
//                ans += 1;
//                break;
//            }
//        }
//    }
//
////    for (int i = 0; i < (n * m); i++) {
////        cout << plots[i] << " ";
////    }
//    cout << ans;
//
//    return 0;
//}