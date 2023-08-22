//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//
//#define q 256 //alphabet size
//#define k 1000000000 //very big number
//#define int long long
//
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//
//
//signed main() {
//    int n, queries;
//    cin >> n;
//    cin >> queries;
//
//    string inp;
//    cin >> inp;
//
//    vector<int> powers(inp.size(), 1);
//    for (int i = 1; i < powers.size(); i++) {
//        powers[i] = (powers[i - 1] * q) % k;
//    }
//
//    vector<int> hashes(inp.size(), 0);
//    hashes[0] = inp[0];
//    for (int i = 1; i < hashes.size(); i++) {
//        hashes[i] = (hashes[i - 1] + powers[i - 1] * inp[i - 1]) % k;
//    }
//
//    int ans = 0;
//    for (int i = 0; i < queries; i++) {
//        int start1, start2, len;
//        cin >> start1 >> start2 >> len;
//        start1 -= 1;
//        start2 -= 1;
//
//        if (((hashes[start1 + len] - hashes[start1]) * powers[start2]) % k  == ((hashes[start2 + len] - hashes[start2]) * powers[start1]) % k) {
//            ans += 1;
//        }
//    }
//
//    cout << ans;
//
//    return 0;
//}