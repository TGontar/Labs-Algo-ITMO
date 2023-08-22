#include "iostream"
#include "string"
#include "vector"
#include "cmath"

#define q 31
#define k 1000000007

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool check_if_equal(vector<vector<int>>& m, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int n1 = x2 - x1 + 1;
    int m1 = y2 - y1 + 1;
    int n2 = x4 - x3 + 1;
    int m2 = y4 - y3 + 1;

    if (n1 != n2 or m1 != m2) {
        return false;
    }

    long long hash1 = 0;
    long long hash2 = 0;
    long long p_pow = 1;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            hash1 = (hash1 * q + m[x1 + i][y1 + j]) % k;
            hash2 = (hash2 * q + m[x3 + i][y3 + j]) % k;
            p_pow = (p_pow * q) % k;
        }
    }

    if (hash1 == hash2) {
        return true;
    }

    for (int i = n1; i < x2 - x1 + 1; i++) {
        for (int j = 0; j < m1; j++) {
            hash1 = (hash1 * q - m[x1 + i - n1][y1 + j] * p_pow % k + k) % k;
            hash1 = (hash1 + m[x1 + i][y1 + j]) % k;

            hash2 = (hash2 * q - m[x3 + i - n1][y3 + j] * p_pow % k + k) % k;
            hash2 = (hash2 + m[x3 + i][y3 + j]) % k;

            if (hash1 == hash2) {
                return true;
            }
        }
    }

    return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int queries;
    cin >> queries;

    vector<string> ans;
    for (int i = 0; i < queries; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        if (check_if_equal(matrix, x1 - 1, y1 - 1, x2 - 1, y2 - 1, x3 - 1, y3 - 1, x4 - 1, y4 - 1)) {
            ans.emplace_back("YES");
        } else {
            ans.emplace_back("NO");
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}