//#include "iostream"
//#include "string"
//#include "vector"
//#include "cmath"
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::vector;
//using std::string;
//
////count max length of prefix-suffix for each substring of a string
//vector<int> prefix_function(string &inputstr) {
//    vector<int> prefixes(inputstr.size(), 0);
//
//    for (int i = 1; i < inputstr.size(); i++) {
//        int k = prefixes[i - 1];
//        while (k > 0 and inputstr[i] != inputstr[k]) {
//            k = prefixes[k - 1];
//        }
//
//        if (inputstr[i] == inputstr[k]) {
//            k += 1;
//        }
//
//        prefixes[i] = k;
//    }
//
//    return prefixes;
//}
//
//
//
//int main() {
//    string inp;
//    cin >> inp;
//
//    vector<int> ans = prefix_function(inp);
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << " ";
//    }
//
//    return 0;
//}