//#include "iostream"
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    for (int i = 1; i < n; i++) {
//        int j = i;
//        int flag = 0;
//        while (j > 0 && arr[j - 1] > arr[j]) {
//            int tmp = arr[j];
//            arr[j] = arr[j - 1];
//            arr[j - 1] = tmp;
//            j--;
//            flag = 1;
//        }
//        if (flag == 1) {
//            for (int k = 0; k < n; k++) {
//                cout << arr[k] << " ";
//            }
//            cout << "\n";
//        }
//    }
//
//    return 0;
//}