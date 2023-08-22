#include "iostream"
#include "cmath"

using std::cout;

long long factorial(long long i) {
    if (i==0) return 1;
    else return i*factorial(i-1);
}

int main() {
    long double ans = 0;
    for (int k = 5; k < 50; k++) {
        ans += (pow(0.4, k)) / (factorial(k - 5));
    }
    cout << ans;
    return 0;
}