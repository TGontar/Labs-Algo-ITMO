#include "iostream"
#include "string"
#include "vector"

#define min_val -10000000


using std::cin;
using std::cout;
using std::endl;
using std::vector;

//continuous method of open addressing
void hash_insert(vector<int> &table, int key, int m) {
    if (table[key % m] != min_val) {
        int temp = key;
        while (table[temp % m] != min_val) {
            temp += 1;
        }

        table[temp % m] = 1;
        return;
    };

    table[key % m] = 1;
}

bool hash_search(vector<int> &table, int key, int m) {
    int tmp = key;
    while (table[tmp % m] != 1) {
        if (table[tmp % m] == min_val or tmp == m) {
            return false;
        } else {
            tmp += 1;
        }
    }

    return true;
}


int main() {
    int n;
    cin >> n;


    //hash_tables
    int m = 1000000;
    vector<int> xs(m, min_val);
    vector<int> ys(m, min_val);

    int count = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (hash_search(xs, x, m) or hash_search(ys, y, m)) {
            continue;
        } else {
            hash_insert(xs, x, m);
            hash_insert(ys, y, m);
            count += 1;
        }
    }

    if (count <= 3) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}