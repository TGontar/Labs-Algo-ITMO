//#include "iostream"
//#include "string"
//#include "vector"
//
//#define min_val 0
//
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::hash;
//
////continuous method of open addressing
//void hash_insert(vector<int> &table, int key, int m, int padd) {
//    table[(key + padd) % m] += 1;
//}
//
//int hash_search(vector<int> &table, int key, int m, int padd) {
//    return table[(key + padd) % m];
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> s(n, 0);
//    for (int i = 0; i < n; i++) {
//        cin >> s[i];
//    }
//
//    //hash_table
//    int m = 10000000;
//    int padding = m / 2;
//    vector<int> diffs(m, min_val);
//
//    int ans = 0;
//
//    for (int i = 0; i < n; i++) {
//        if (hash_search(diffs, s[i] - i, m, padding) != 0) {
//            ans += hash_search(diffs, s[i] - i, m, padding);
//        }
//
//        hash_insert(diffs, s[i] - i, m, padding);
//    }
//
//
//    cout << ans;
//
//    return 0;
//}