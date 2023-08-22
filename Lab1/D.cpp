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
//    int ans = 0;
//    for (int i = 1; i<(n-1); i++) {
//        if ((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) {
//            ans += 1;
//        }
//    }
//
//    cout << ans << endl;
//
//    return 0;
//}