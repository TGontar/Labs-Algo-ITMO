//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//
//#define q 256 //alphabet size
//#define k 2000000000 //very big number
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//
////rabin karp algorithm for substring searching
//int rabin_karp_matcher(string &inputstr, string &substr) {
//    int n = inputstr.size();
//    int m = substr.size();
//    int hash_substr = 0;
//    for (int i = 0; i < m; i++) {
//        hash_substr = (q * hash_substr + substr[i]) % k;
//    }
//    int hash_current = 0;
//    for (int i = 0; i < m; i++) {
//        hash_current = (q * hash_current + inputstr[i]) % k;
//    }
//
//    int max_degree = pow(q, m-1);
//    vector<int> ans;
//    for (int i = 0; i <= (n - m); i++) {
//        if (hash_current == hash_substr) {
//            bool flag = true;
//
//            for (int j = i; j < (i + m); j++) {
//                if (substr[j - i] != inputstr[j]) {
//                    flag = false;
//                    break;
//                }
//            }
//
//            if (flag) {
//                return i;
//            }
//        }
//
//        hash_current = (q * (hash_current - max_degree*inputstr[i]) + inputstr[i + m]) % k;
//    }
//
//    return -1;
//}
//
//
//int main() {
//    string inp;
//    string sub;
//    cin >> inp;
//    cin >> sub;
//
//    int answer = rabin_karp_matcher(inp, sub);
//    cout << answer;
//    return 0;
//}