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
//    int minimum1 = arr[0];
//    int pos = 0;
//    for (int i=0; i<n; i++) {
//        if (arr[i] < minimum1) {
//            minimum1 = arr[i];
//            pos = i;
//        }
//    }
//
//    arr[pos] = 2111111111;
//    int minimum2 = arr[0];
//    for (int i=0; i<n; i++) {
//        if (arr[i] < minimum2) {
//            minimum2 = arr[i];
//        }
//    }
//    cout << minimum1 << " " << minimum2;
//
//    return 0;
//}