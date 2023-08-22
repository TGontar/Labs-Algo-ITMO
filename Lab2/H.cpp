//#include "iostream"
//#include "vector"
//
//using std::cout;
//using std::cin;
//
//int main() {
//    int n;
//    cin >> n;
//    std::vector<int> lst;
//    for (int i = 0; i < n; i++) {
//        int left;
//        int right;
//        cin >> left;
//        cin >> right;
//        for (int j = 0; j <= (right - left); j++) {
//            int flag = 0;
////            for (int k = 0; k <= lst.size(); k++) {
////                if (lst[k] == left + j) {
////                    flag = 1;
////                    break;
////                }
////            }
//            if (flag == 0) {
//                lst.push_back(left + j);
//            }
//        }
//    }
//
//    for (int i = 1; i < lst.size(); i++) {
//        int j = i;
//        while (j > 0 && lst[j - 1] > lst[j]) {
//            std::swap(lst[j], lst[j-1]);
//            j--;
//        }
//    }
//
//    int ans = lst.size();
//    for (int i = 0; i < (lst.size()-1); i++) {
//        if (lst[i] == lst[i+1]) {
//            ans -= 1;
//        }
//    }
//
//
//    cout << ans;
////
////    for (int i = 0; i < lst.size(); i++) {
////        cout << lst[i] << " ";
////    }
//
//    return 0;
//}