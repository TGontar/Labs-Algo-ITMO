//#include "iostream"
//#include "string"
//#include "vector"
//#include "math.h"
//
//using std::cin;
//using std::cout;
//using std::string;
////using std::endl;
//using std::vector;
//
//void razbienie(int arr[], int l, int r, int k, int aver, vector<int> &ans) {
//    int cnt = 0;
//    int n = r;
//    while (cnt < k-1) {
//        int mid = (l + r) / 2;
//        if (r - l < 2) {
//            if (abs(arr[l] - aver) < abs(arr[r] - aver)) {
//                ans.push_back(l+1);
//                l = r;
//            } else {
//                ans.push_back(r+1);
//                l = r + 1;
//            }
//            r = n;
//            cnt += 1;
//        } else if (aver <= arr[r] - arr[mid]) {
//            r = mid;
//        } else {
//            l = mid;
//        }
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//    int k;
//    cin >> k;
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    int sums[n + 1];
//    int count = 0;
//    sums[0] = 0;
//    for (int i = 0; i < n; i++) {
//        count += arr[i];
//        sums[i+1] = count;
//    }
//
////    for (int i = 0; i<=n; i++) {
////        cout << sums[i] << " ";
////    }
//    int aver = sums[n] / k;
//    vector<int> ans;
//
//    razbienie(sums, 0, n, k, aver, ans);
//
//    for (long long  i = 0; i < ans.size(); i++) {
//        cout << ans[i] << " ";
//    }
//
//    return 0;
//}