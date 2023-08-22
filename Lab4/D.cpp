//#include "iostream"
//#include "cmath"
//#include "string"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
//using std::vector;
//
//int digit(int n, int k) {
//    int a = pow(10, k);
//    int b = pow(10, k-1);
//    int ans = (n % a) / b;
//    return ans;
//}
//
//int letter(string n, int m, int k) {
//    char letter = n[m - k];
//    int ans = letter - 'a';
//    return ans;
//}
//
//
//void RadixSort(vector<string> &arr, int n, int m, int kk) {
//    for (int i = 1; i <= m; i++) {
//        vector<int> C;
//        vector<string> B;
//        for (int bb = 0; bb < n; bb++) {
//            B.push_back("");
//        }
//
//
//        for (int j = 0; j < 26; j++) {
//            C.push_back(0);
//        }
//        for (int j = 0; j < n; j++) {
//            int d = letter(arr[j], m, i);
//            C[d] += 1;
//        }
//        int cnt = 0;
//        for (int j = 0; j < 26; j++) {
//            int tmp = C[j];
//            C[j] = cnt;
//            cnt += tmp;
//        }
//        for (int j = 0; j < n; j++) {
//            int d = letter(arr[j], m, i);
//            B[C[d]] = arr[j];
//            C[d] += 1;
//        }
//        arr = B;
//        if (i == kk) {
//            for (int i = 0; i < n; i++) {
//                cout << arr[i] << "\n";
//            }
//            exit(0);
//        }
//    }
//    return;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    int m;
//    cin >> m;
//    int k;
//    cin >> k;
//
//    vector<string> arr;
//    for (int i = 0; i < n; i++) {
//        string inp;
//        cin >> inp;
//        arr.push_back(inp);
//    }
//
//    RadixSort(arr, n, m, k);
//
//
//
//    return 0;
//}