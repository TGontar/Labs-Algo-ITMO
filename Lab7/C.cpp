#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::string;
using std::atoi;
using std::min;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    if (n == 0 or m == 0) {
        exit(0);
    }
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }


    int left[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            left[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                if (arr[i][j] == '5') {
                    left[i][j] = 1;
                } else {
                    left[i][j] = 0;
                }
            } else {
                if (arr[i][j] == '5') {
                    left[i][j] = left[i][j - 1] + 1;
                } else {
                    left[i][j] = 0;
                }
            }
        }
    }

    int down[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            down[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (arr[i][j] == '5') {
                    down[i][j] = 1;
                } else {
                    down[i][j] = 0;
                }
            } else {
                if (arr[i][j] == '5') {
                    down[i][j] = down[i - 1][j] + 1;
                } else {
                    down[i][j] = 0;
                }
            }
        }
    }


    int dp[n][m];
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == '5') {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (arr[0][i] == '5') {
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(min(left[i][j], down[i][j]), dp[i - 1][j - 1] + 1);
        }
    }

    int max = 0;
    int coords[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] >= max) {
                max = dp[i][j];
                coords[0] = i;
                coords[1] = j;
            }
        }
    }

    coords[0] = coords[0] - max + 2;
    coords[1] = coords[1] - max + 2;

    cout << max << " " << coords[0] << " " << coords[1] << "\n";

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    return 0;
}