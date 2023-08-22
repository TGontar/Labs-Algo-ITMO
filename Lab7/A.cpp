#include "iostream"
#include "vector"

using std::cin;
using std::cout;
using std::max;
using std::vector;

    int main() {
    int n;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int length = dp[0];
    for (int i = 0; i < n; i++) {
        if (dp[i] > length) {
            pos = i;
            length = dp[i];
        }
    }

    vector<int> ans;
    while (pos != -1) {
        ans.push_back(arr[pos]);
        pos = prev[pos];
    }

    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }


    return 0;
}