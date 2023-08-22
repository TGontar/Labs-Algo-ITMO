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
//    int minn = maxx;
//    for (int i = 0; i < n; i++) {
//        if (arr[i] < minn) {
//            minn = arr[i];
//        }
//    }
//
//    int lenC = maxx - minn + 1;
//    int C[lenC];
//    for (int i = 0; i < lenC; i++) {
//        C[i] = 0;
//    }
//
//    for (int i = 0; i < n; i++) {
//        C[arr[i]-minn] += 1;
//    }
//    int cnt = 0;
//    for (int i = 0; i < lenC; i++) {
//        for (int j = 0; j < C[i]; j++) {
//            arr[cnt] = minn + i;
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