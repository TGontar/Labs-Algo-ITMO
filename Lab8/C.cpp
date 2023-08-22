//#include "iostream"
//#include "vector"
//#include "string"
//
//using std::cin;
//using std::cout;
//using std::vector;
//using std::string;
//
//void hamming(string arr, int n, vector<string> &answer) {
//    int mistake = 0;
//
//    //check control bits
//    for (int i = 1; i <= n; i *= 2) {
//        int cnt = 0;
//        int counterones = 0;
//        bool check = true;
//
//        //check info bits for each control bit
//        for (int j = i; j <= n; j++, cnt++) {
//            if (cnt == 0) {
//                if (arr[i-1] == '1') {
//                    counterones += 1;
//                }
//                continue;
//            }
//            if (cnt % i == 0) {
//                check = !check;
//            }
//            if (check) {
//                if (arr[j-1] == '1') {
//                    counterones += 1;
//                }
//            }
//        }
//
//        //check if contol bit xor all info bits is 1
//        if (counterones % 2 != 0) {
//            mistake += i;
//        }
//
//    }
//
//    //correct the mistake
//    if (mistake != 0) {
//        if (arr[mistake - 1] == '0') {
//            arr[mistake - 1] = '1';
//        } else {
//            arr[mistake - 1] = '0';
//        }
//    }
//
//    //write into final answer
//    string itog;
//    for (int i = 1; i <= n; i++) {
//        if ((i & (i - 1)) != 0) {
//            itog.push_back(arr[i-1]);
//        }
//    }
//
//    answer.push_back(itog);
//
//}
//
//int main() {
//    int t;
//    cin >> t;
//    vector<string> ans;
//    while (true) {
//        string str;
//        cin >> str;
//        if (str.empty()) {
//            break;
//        } else {
//            hamming(str, str.size(), ans);
//        }
//    }
//
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}