//#include "iostream"
//
//using std::cout;
//using std::cin;
//
//int main() {
//    int n;
//    cin >> n;
//
//    int arr[n][2];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 2; j++) {
//            cin >> arr[i][j];
//        }
//    }
//
//    //Сортировка вставками для баллов
//    for (int i = 1; i < n; i++) {
//        int j = i;
//        while (j > 0 && arr[j - 1][1] > arr[j][1]) {
//            int tmp1 = arr[j][0];
//            int tmp2 = arr[j][1];
//            arr[j][0] = arr[j - 1][0];
//            arr[j][1] = arr[j - 1][1];
//            arr[j - 1][0] = tmp1;
//            arr[j - 1][1] = tmp2;
//            j--;
//        }
//    }
//
//    //Сортировка вставками для номеров, сортирует по убыванию потому что в ответе номера должны быть по возрастанию,
//    // а массив у меня выводится наоборот
//    for (int i = 1; i < n; i++) {
//        int j = i;
//        while (j > 0 && arr[j - 1][0] < arr[j][0] && arr[j-1][1] == arr[j][1]) {
//            int tmp1 = arr[j][0];
//            int tmp2 = arr[j][1];
//            arr[j][0] = arr[j - 1][0];
//            arr[j][1] = arr[j - 1][1];
//            arr[j - 1][0] = tmp1;
//            arr[j - 1][1] = tmp2;
//            j--;
//        }
//    }
//
//    for (int i = n-1; i >= 0; i--) {
//        for (int j = 0; j < 2; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//
//    return 0;
//}