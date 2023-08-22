//#include "iostream"
//
//using std::cin;
//using std::cout;
//
//void CountSort(int arr[], int n) {
//    int maxx = 0;
//    for (int i = 0; i < n; i++) {
//        if (arr[i] > maxx) {
//            maxx = arr[i];
//        }
//    }
//
//    int C[maxx + 1];
//    for (int i = 0; i < maxx + 1; i++) {
//        C[i] = 0;
//    }
//
//    for (int i = 0; i < n; i++) {
//        C[arr[i]] += 1;
//    }
//    int cnt = 0;
//    for (int i = 0; i < maxx + 1; i++) {
//        for (int j = 0; j < C[i]; j++) {
//            arr[cnt] = i;
//            cnt += 1;
//        }
//    }
//
//    return;
//}
//
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
//    CountSort(arr, n);
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}