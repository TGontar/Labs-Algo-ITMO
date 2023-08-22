#include "iostream"
#include "string"
#include "vector"
#include "math.h"

using std::cin;
using std::cout;
using std::string;
//using std::endl;
using std::vector;


void razbienie(int arr[], int n, long long l, long long r, int k, vector<long long> &ans) {
    while (true) {
        if (l == r) {
            long long subsum = 0;
            int cnt = 0;
            int borders[n];
            for (int i = 0; i < n; i++) {
                borders[i] = 0;
            }

            for (int i = 0; i < n - 1; i++) {
                subsum += arr[i];
                if (subsum + arr[i + 1] > r) {
                    cnt += 1;
                    borders[i] = 1;
//                    ans.push_back(i+1);
                    subsum = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                if (cnt >= k - 1) {
                    break;
                } else if (borders[i] == 0) {
                    borders[i] = 1;
                    cnt += 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (borders[i] == 1) {
                    ans.push_back(i+1);
                }
            }
            break;
        }
        long long mid = (l + r) / 2;
        int cnt = 0;
        long long subsum = 0;
        for (int i = 0; i < n - 1; i++) {
            subsum += arr[i];
            if (subsum + arr[i + 1] > mid) {
                cnt += 1;
                subsum = 0;
            }
        }
        if (cnt <= k-1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}



int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    vector<long long> ans;
    razbienie(arr, n, max, sum, k, ans);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}