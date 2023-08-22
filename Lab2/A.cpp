//#include <iostream>
//
//using std::cin;
//using std::cout;
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
//    int a, x;
//    cin >> a;
//    cin >> x;
//
//    int ans[n + 1];
//    for (int i = 0; i < n; i++) {
//        ans[i] = arr[i];
//    }
//    ans[n] = a;
//
//    int j = n;
//    while (j > (x - 1)) {
//        int tmp = ans[j];
//        ans[j] = ans[j - 1];
//        ans[j - 1] = tmp;
//        j--;
//    }
//
//    for (int i = 0; i < (n+1); i++) {
//        cout << ans[i] << " ";
//    }
//
//    return 0;
//}
