////int main() {
////    if (str[0] == 'p') {
////        int bf = 0;
////        for (int i = 5; i < str.size(); i++) {
////            int k = str[i] - '0';
////            bf += k * pow(10, (str.size() - i - 1));
////        }
////        cout << bf;
////    } else if (str[0] == 'd')
////}
////
////    return 0;
////}
//#include "iostream"
//#include "vector"
//#include "string"
//#include "cstring"
//#include "cmath"
//
//using std::cin;
//using std::cout;
//using std::swap;
//using std::vector;
//using std::string;
//using std::getline;
//
//void siftDown(vector<int> &arr, int n, int k) {
//    int tmp = k;
//    if (2 * k + 1 < n) {
//        if (arr[tmp] > arr[2 * k + 1]) {
//            tmp = 2 * k + 1;
//        }
//    }
//    if (2 * k + 2 < n) {
//        if (arr[tmp] > arr[2 * k + 2]) {
//            tmp = 2 * k + 2;
//        }
//    }
//    if (tmp != k) {
//        swap(arr[k], arr[tmp]);
//        siftDown(arr, n, tmp);
//    } else {
//        return;
//    }
//}
//
//void siftUp(vector<int> &arr, int n, int k) {
//    int tmp = k;
//    if ((k - 1) / 2 >= 0) {
//        if (arr[tmp] < arr[(k - 1) / 2]) {
//            tmp = (k - 1) / 2;
//        }
//    }
//    if ((k - 2) / 2 >= 0) {
//        if (arr[tmp] < arr[(k - 2) / 2]) {
//            tmp = (k - 2) / 2;
//        }
//    }
//    if (tmp != k) {
//        swap(arr[k], arr[tmp]);
//        siftUp(arr, n, tmp);
//    }
//
//}
//
//
//void buildHeap(vector<int> &arr, int n) {
//    for (int i = n / 2; i >= 0; i--) {
//        siftDown(arr, n, i);
//    }
//
//}
//
//void pushElem(vector<int> &arr, int n, int k) {
//    arr.push_back(k);
//    int size = n + 1;
//    siftUp(arr, size, size-1);
//}
//
//int extractMin(vector<int> &arr, int n) {
//    if (n == 0) {
//        return 2111111111;
//    }
//    int ans = arr[0];
//    swap(arr[0], arr[n-1]);
//    arr.pop_back();
//    int size = n - 1;
//    siftDown(arr, size, 0);
//    return ans;
//}
//
//void decreaseKey(vector<int> &arr, int n, int x, int y) {
//    int change = 0;
//    for (int i = 0; i < n; i++) {
//        if (arr[i] == x) {
//            change = i;
//            break;
//        }
//    }
//    arr[change] = y;
//    siftUp(arr, n, change);
//}
//
//
//int main() {
//    vector<int> ans;
//    vector<int> pushes;
//    vector<int> queue;
//    while (true) {
//        string str;
//        cin >> str;
//        if (str.empty()) {
//            break;
//        } else if (str[0] == 'p') {
//            int ins;
//            cin >> ins;
//            pushElem(queue, queue.size(), ins);
//            pushes.push_back(ins);
//        } else if (str[0] == 'd') {
//            int a;
//            cin >> a;
//            int b;
//            cin >> b;
//            decreaseKey(queue, queue.size(), pushes[a-1], b);
//        } else {
//            int minimum = extractMin(queue, queue.size());
//            ans.push_back(minimum);
//        }
//    }
//    for (int i = 0; i < ans.size(); i++) {
//        if (ans[i] == 2111111111) {
//            cout << '*' << '\n';
//        } else {
//            cout << ans[i] << '\n';
//        }
//    }
//    return 0;
//}
