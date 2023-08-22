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
using std::copy;

//disjoint set union for graph
class DSU {
private:
    vector<int> parent;
    vector<int> size;
    int n;
    int diff;
public:
    DSU(int count) {
        n = count;
        diff = count;
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
            diff -= size[b];
        }
    }

    //check if the mst is completed
    bool check_if_one_comp() {
        return (diff == 1 or diff == 0);
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


//mark edges with dfs - inorder traversal of the tree
void DFS_mark_vertexes(vector<vector<pair<int, int>>> &graph, vector<int> &colors, vector<int> &heights, vector<int> &parents, int cur,
                  int prev, int curheight) {
    heights[cur] = curheight;
    parents[cur] = prev;
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i].first;
        if (colors[to] == 0) {
            if (to != prev) {
                DFS_mark_vertexes(graph, colors, heights, parents, to, cur, curheight + 1);
            }
        }
    }
    colors[cur] = 2;
};

void check_weight(vector<vector<pair<int, int>>> &graph, int from, int to, int *ans) {
    for (auto i : graph[from]) {
        if (i.first == to) {
            if (i.second > *ans) {
                *ans = i.second;
            }

            break;
        }
    }
}

//Least Common Ancestor algorithm
int LCA(vector<vector<pair<int, int>>> &graph, vector<int> &parents, vector<int> &heights, int v, int a, int b) {
    int ha = heights[a];
    int hb = heights[b];

    int ans = 0;

    //make heights of first and second equal
    while (ha != hb) {
        if (ha > hb) {
            check_weight(graph, a, parents[a], &ans);
            a = parents[a];
            ha -= 1;
        } else {
            check_weight(graph, b, parents[b], &ans);
            b = parents[b];
            hb -= 1;
        }
    }

    //go up until finding LCA
    while (a != b) {
        check_weight(graph, a, parents[a], &ans);
        check_weight(graph, b, parents[b], &ans);
        a = parents[a];
        b = parents[b];
        ha -= 1;
        hb -= 1;
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
        edges.push_back({from - 1, to - 1, weight, 0, i});
    }

    //sort the edges list
    quick_sort(edges, 0, edges.size() - 1);

    //do Kruscal for regular mst
    DSU comps = DSU(v);
    int mstsize = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (comps.find_set(edges[i][0]) != comps.find_set(edges[i][1])) {
            comps.union_sets(edges[i][0], edges[i][1]);
            mstsize += edges[i][2];
            edges[i][3] = 1;
        }

    }

    //make adjacency list for current tree
    vector<vector<pair<int, int>>> vertexes(v, vector<pair<int, int>>());

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][3] == 1) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            vertexes[from].push_back({to, weight});
            vertexes[to].push_back({from, weight});
        }
    }

    //do traversal of the tree and mark heights for vertexes
    vector<int> parents(v, mx);
    vector<int> heights(v, mx);
    vector<int> colors(v, 0);
    DFS_mark_vertexes(vertexes, colors, heights, parents, 0, mx, 1);

    //make requests
    vector<int> ans(e, 0);
    for (int num = 0; num < e; num++) {
        if (edges[num][3] == 1) {
            ans[edges[num][4]] = mstsize;
        } else {
            int temp = mstsize + edges[num][2];
            int minus = LCA(vertexes, parents, heights, v, edges[num][0], edges[num][1]);
            temp -= minus;
            ans[edges[num][4]] = temp;
        }
    }

    for (int i = 0; i < e; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}