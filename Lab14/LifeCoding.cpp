//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//
//#define q 31 //alphabet size
//#define k 1000000007 //very big number
//#define int unsigned long long
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//
//bool check_if_pallindrome(string &a, int shift) {
//    int n = a.size();
//    for (int i = 0; i < n / 2; i++) {
//        if (a[(shift + i) % n] != a[(shift + n - i - 1) % n]) {
//            return false;
//        }
//    }
//    return true;
//}
//
////rabin karp algorithm for substring searching
//bool rabin_karp_matcher(string &inputstr) {
//    int n = inputstr.size();
//    int hash_left = 0;
//    for (int i = 0; i < n / 2; i++) {
//        hash_left = (q * hash_left + inputstr[i]) % k;
//    }
//
//    if (n % 2 == 1) {
//        hash_left = (q * hash_left + inputstr[n / 2]) % k;
//    }
//
//    int hash_right = 0;
//    for (int i = n - 1; i >= n / 2; i--) {
//        hash_right = (q * hash_right + inputstr[i]) % k;
//    }
//
//    int max_degree = 0;
//    if (n % 2 == 1) {
//        max_degree = pow(q, n / 2);
//    } else {
//        max_degree = pow(q, n / 2 - 1);
//    }
//
//    for (int i = 1; i < n; i++) {
//        if (hash_left == hash_right) {
//            if (check_if_pallindrome(inputstr, i - 1)) {
//                return true;
//            }
//        }
//
//        if (n % 2 == 1) {
//            hash_left = (q * (hash_left - max_degree * inputstr[i - 1]) + inputstr[(i + n / 2) % n]) % k;
//            hash_right = ((hash_right - inputstr[i + n / 2 - 1]) / q + max_degree * inputstr[i - 1]) % k;
//        } else {
//            hash_left = (q * (hash_left - max_degree * inputstr[i - 1]) + inputstr[(i + n / 2 - 1) % n]) % k;
//            hash_right = ((hash_right - inputstr[i + n / 2]) / q + max_degree * inputstr[i - 1]) % k;
//        }
//    }
//
//    return false;
//}
//
//
//signed main() {
//    string inp;
//    cin >> inp;
//
//    if (inp.size() == 1 or inp.size() == 0) {
//        cout << "YES";
//        exit(0);
//    }
//
//    if (rabin_karp_matcher(inp)) {
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
//
//
//    return 0;
//}