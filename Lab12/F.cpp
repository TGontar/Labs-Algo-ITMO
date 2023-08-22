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
    vector<long long> parent;
    vector<long long> size;
    long long n;
    long long diff;
public:
    DSU(long long count) {
        n = count;
        diff = count;
        parent = vector<long long>(n, 0);
        for (long long i = 0; i < n; i++) {
            parent[i] = i;
        }
        size = vector<long long>(n, 1);
    }

    void make_set(long long v) {
        parent[v] = v;
        size[v] = 1;
    }


    long long find_set(long long v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(long long a, long long b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            diff -= size[b];
        }
    }

    //check if the mst is completed
    bool check_if_one_comp() {
        return (diff == 1 or diff == 0);
    }

};

//quicksort for edges list
void quick_sort(vector<vector<long long>> &arr, long long l, long long r) {
    long long i = l;
    long long j = r;
    long long x = arr[(l + r) / 2][2];
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
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long v, e;
    cin >> v;
    cin >> e;

    //create edges list
    vector<vector<long long>> edges;

    for (long long i = 0; i < e; i++) {
        long long from, to, weight;
        cin >> from;
        cin >> to;
        cin >> weight;
        edges.push_back({from - 1, to - 1, weight, 0});
    }

    //first MST, kruskal algo
    //sort the edges list
    quick_sort(edges, 0, edges.size() - 1);

    //components of connectivity
    DSU comps = DSU(v);

    //check each edge if it makes a cycle after adding
    long long ans1 = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (comps.find_set(edges[i][0]) != comps.find_set(edges[i][1])) {
            comps.union_sets(edges[i][0], edges[i][1]);
            ans1 += edges[i][2];
            edges[i][3] = 1;
        }

        if (comps.check_if_one_comp()) {
            break;
        }
    }


    //second MST
    //find 2 minimally different edges
    vector<long long> deltas(e, 0);
    deltas[0] = mx;
    for (int i = 1; i < e; i++) {
        deltas[i] = edges[i][2] - edges[i - 1][2];
    }

    long long minimum = mx;
    int minind = mx;
    for (int i = 1; i < deltas.size(); i++) {
        if (deltas[i] < minimum and edges[i][3] == 0 and edges[i - 1][3] == 1) {
            minimum = deltas[i];
            minind = i;
        }
    }

    //make second MST
    DSU comps2 = DSU(v);
    comps2.union_sets(edges[minind][0], edges[minind][1]);
    long long ans2 = edges[minind][2];
    for (int i = 0; i < edges.size(); i++) {
        if (comps2.find_set(edges[i][0]) != comps2.find_set(edges[i][1])) {
            comps2.union_sets(edges[i][0], edges[i][1]);
            ans2 += edges[i][2];
        }

        if (comps2.check_if_one_comp()) {
            break;
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}