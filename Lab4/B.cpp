#include "iostream"

using std::cin;
using std::cout;
using std::swap;

void siftDown(int arr[], int n, int k) {
    int tmp = k;
    if (2*k + 1 < n) {
        if (arr[tmp] < arr[2*k + 1]) {
            tmp = 2*k + 1;
        }
    }
    if (2*k + 2 < n) {
        if (arr[tmp] < arr[2*k + 2]) {
            tmp = 2*k + 2;
        }
    }
    if (tmp != k) {
        swap(arr[k], arr[tmp]);
        siftDown(arr, n, tmp);
    } else {
        return;
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2; i >= 0; i--) {
        siftDown(arr, n, i);
    }

}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    int hsize = n;
    for (int i = 0; i < n; i++) {
        swap(arr[0], arr[hsize-1]);
        hsize -= 1;
        siftDown(arr, hsize, 0);
    }

}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}