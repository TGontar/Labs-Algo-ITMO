//#include "iostream"
//#include "string"
//#include "vector"
//
//#define min_val -10000000
//
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//
//int hash_easy(int key, int m) {
//    return key % m;
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    int m = 10000000;
//    vector<int> table(m, min_val);
//
//    for (int i = 0; i < n; i++) {
//        int k;
//        cin >> k;
//        table[hash_easy(k, m)] = k;
//    }
//
//    bool flag = false;
//    for (int i = 0; i < n; i++) {
//        int k;
//        cin >> k;
//        if (table[hash_easy(k, m)] == min_val) {
//            flag = true;
//        }
//    }
//
//    if (flag) {
//        cout << "NO";
//    } else {
//        cout << "YES";
//    }
//
//    return 0;
//}