//#include "iostream"
//
//using std::cin;
//using std::cout;
//
//int  *CountSort(int arr[], int n) {
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
//        C[arr[i] - minn] += 1;
//    }
//
//    for (int i=1; i < lenC; i++) {
//        C[i] = C[i] + C[i-1];
//    }
//
//    int *ans = new int[n];
//    for (int i = n-1; i>=0; i--) {
//        ans[C[arr[i]-minn] - 1] = arr[i];
//        C[arr[i] - minn] -= 1;
//    }
//
//    return ans;
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
//    int *ans = CountSort(arr, n);
//
//    for (int i = 0; i < n; i++) {
//        cout << ans[i] << " ";
//    }
//
//    return 0;
//}