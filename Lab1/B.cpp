//#include "iostream"
//
//using std::cout;
//using std::cin;
//using std::endl;
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
//    int ans[n];
//    ans[0] = arr[n - 1];
//    for (int i = 0; i < (n - 1); i++) {
//        ans[i+1] = arr[i];
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << ans[i] << " ";
//    }
//
//        return 0;
//}