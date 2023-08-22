//#include <stdio.h>
//
//
//void k_stat(int arr[], int l, int r, int k) {
//    int i = l;
//    int j = r;
//    int x = arr[(l + r) / 2];
//    while (i <= j) {
//        while (arr[i] < x) {
//            i++;
//        }
//        while (arr[j] > x) {
//            j--;
//        }
//        if (i <= j) {
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//            j--;
//        }
//    }
//    if ((j < k - 1) && (k - 1 < i)) {
//        printf("%d", k -1);
//        return;
//    } else if ((l <= j) && (k - 1 <= j)) {
//        k_stat(arr, l, j, k);
//    } else if ((i <= r) && (k - 1 >= i)) {
//        k_stat(arr, i, r, k);
//    }
//}
//
//int main() {
//    int n, k;
//    scanf("%d", &n);
//    scanf("%d", &k);
//
//    int A, B, C;
//    scanf("%d", &A);
//    scanf("%d", &B);
//    scanf("%d", &C);
//
//    int arr[n];
//    for (int i = 0; i < 2; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    for (int i = 2; i < n; i++) {
//        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
//    }
//
//    k_stat(arr, 0, n-1, k);
//
//    return 0;
//}
