#include <iostream>
#include <vector>

using namespace std;

const int min_val = -10000000;

class HashTable {
private:
    vector<int> table;
    const int m = 1000000;

public:
    HashTable() {
        table.resize(m, min_val);
    }

    int hash_insert(int key) {
        int index = key % m;
        if (table[index] != min_val) {
            // иначе ищем свободную ячейку
            while (table[index] != min_val) {
                index = (index + 1) % m;
            }

            table[index] = key;

            return 1;
        }
        table[index] = key;
        return 1;
    }

    bool hash_search(int key) {
        int tmp = key;
        while (table[tmp % m] != key) { // проверяем произвольное число вместо флага
            if (table[tmp % m] == min_val or tmp == m) {
                return false;
            } else {
                tmp += 1;
            }
        }
        return true;
    }
};

int main() {
    int n;
    int count = 0;
    cin >> n;

    HashTable xs = HashTable();
    HashTable ys = HashTable();

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!xs.hash_search(x) && !ys.hash_search(y)) {
            xs.hash_insert(x);
            ys.hash_insert(y);
            count += 1;
        }
    }

    if (count <= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}