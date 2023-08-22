#include "iostream"
#include "string"

using std::cin;
using std::cout;
using std::max;

int put_heights(int arr[][4], int k) {
    if (k == 0) {
        return 0;
    } else {
        int left = put_heights(arr, arr[k][1]);
        int right = put_heights(arr, arr[k][2]);
        int ans = (left > right) ? (left) : (right);
        arr[k][3] = 1 + ans;
        return 1 + ans;
    }
}


int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        exit(0);
    }
    int values[n + 1][4];
    values[0][0] = 0;
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> values[i][0];
        cin >> values[i][1];
        cin >> values[i][2];
        values[i][3] = 0;
    }

    put_heights(values, 1);
    int ans[n];
    for (int i = 1; i<=n; i++) {
        ans[i-1] = values[values[i][2]][3] - values[values[i][1]][3];
    }
    for (int i = 0; i<n; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}