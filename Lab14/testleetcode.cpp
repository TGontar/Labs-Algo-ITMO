//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//
//#define q 17 // alphabet size
//#define k 1000000007 // very big number
//
//using std::vector;
//using std::string;
//
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        int n = haystack.size();
//        int m = needle.size();
//        if (m == 0) {
//            return 0;
//        }
//
//        int hash_needle = 0;
//        for (int i = 0; i < m; i++) {
//            hash_needle = (q * hash_needle + needle[i]) % k;
//        }
//
//        int hash_current = 0;
//        for (int i = 0; i < m; i++) {
//            hash_current = (q * hash_current + haystack[i]) % k;
//        }
//
//        int max_degree = 1;
//        for (int i = 0; i < m - 1; i++) {
//            max_degree = (max_degree * q) % k;
//        }
//
//        for (int i = 0; i <= (n - m); i++) {
//            if (hash_current == hash_needle) {
//                bool flag = true;
//
//                for (int j = i; j < (i + m); j++) {
//                    if (needle[j - i] != haystack[j]) {
//                        flag = false;
//                        break;
//                    }
//                }
//
//                if (flag) {
//                    return i;
//                }
//            }
//
//            if (i < (n - m)) {
//                hash_current = ((q * (hash_current - (max_degree * haystack[i]) % k + k)) % k + haystack[i + m]) % k;
//            }
//        }
//
//        return -1;
//    }
//};
