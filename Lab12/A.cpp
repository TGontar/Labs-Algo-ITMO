#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

#define mx 10000000

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::queue;
using std::reverse;
using std::pair;
using std::min;
using std::max;
using std::swap;
using std::endl;

//disjoint set union for graph
class DSU {
private:
    vector<int> parent;
    vector<int> size;
    int n;
public:
    DSU(int count) {
        n = count;
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size = vector<int>(n, 1);
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }


    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

};

//quicksort for edges list
void quick_sort(vector<vector<int>> &arr, int l, int r) {
    int i = l;
    int j = r;
    int x = arr[(l + r) / 2][2];
    while (i <= j) {
        while (arr[i][2] < x) {
            i++;
        }
        while (arr[j][2] > x) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        quick_sort(arr, l, j);
    }
    if (i < r) {
        quick_sort(arr, i, r);
    }
}

int main() {
    int v, e;
    cin >> v;
    cin >> e;

    //create edges list
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from;
        cin >> to;
        cin >> weight;
        edges.push_back({from - 1, to - 1, weight});
    }

    //sort the edges list
    quick_sort(edges, 0, edges.size() - 1);
    //components of connectivity
    DSU comps = DSU(v);

    //check each edge if it makes a cycle after adding
    int ans = 0;
    for (auto i:edges) {
        if (comps.find_set(i[0]) != comps.find_set(i[1])) {
            comps.union_sets(i[0], i[1]);
            ans += i[2];
        }
    }


    cout << ans;


    return 0;
}