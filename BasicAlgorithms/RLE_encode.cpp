//#include "iostream"
//
//using std::cin;
//using std::cout;
//using std::string;
//
//void RLE(string str) {
//    int n = str.size();
//    for (int i = 0; i < n; i++) {
//        int count = 1;
//        while (i < n-1 and str[i] == str[i+1]) {
//            count += 1;
//            i++;
//        }
//        cout << str[i] << count;
//    }
//
//}
//
//int main() {
//    string str1;
//    cin >> str1;
//    RLE(str1);
//    return 0;
//}