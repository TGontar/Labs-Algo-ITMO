#include "iostream"
#include "vector"
#include "cmath"

using std::cin;
using std::cout;
using std::endl;

void gray_codes(int **arr, int n) {
    arr[0][n - 1] = 0;
    arr[1][n - 1] = 1;
    int p = 2;
    for (int i = 2; i <= n; i++) {
        int t = p;
        p *= 2;
        for (int k = (p / 2 + 1); k <= p; k++) {
            for (int cpy = 0; cpy < n; cpy++) {
                arr[k - 1][cpy] = arr[t - 1][cpy];
            }
            arr[t - 1][n - i] = 0;
            arr[k - 1][n - i] = 1;
            t -= 1;
        }
    }

    return;
}


int main() {
    int n;
    cin >> n;
    int num_codes = (int) pow(2, n);

    int **codes = new int *[num_codes];
    for (int i = 0; i < num_codes; i++) {
        codes[i] = new int[n];
    }

    gray_codes(codes, n);

    for (int i = 0; i < num_codes; i++) {
        for (int j = 0; j < n; j++) {
            cout << codes[i][j];
        }
        cout << "\n";
    }

    return 0;
}