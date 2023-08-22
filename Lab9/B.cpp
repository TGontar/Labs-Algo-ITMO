#include "iostream"
#include "vector"
#include "algorithm"

using std::vector;
using std::cin;
using std::cout;
using std::copy_n;

//check the cycles via dfs
void DFS_check_cycle(vector<vector<int>> &graph, int colors[], int cur, int prev) {
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (colors[to - 1] == 0) {
            if (to - 1 != prev) {
                DFS_check_cycle(graph, colors, to - 1, cur);
            }
        }
        if (colors[to - 1] == 1) {
            if (to - 1 != prev) {
                cout << "YES";
                exit(0);
            }
        }
    }
    colors[cur] = 2;
};


int main() {
    int v, e;
    cin >> v;
    cin >> e;

    //create adjacency list
    vector<vector<int>> vertexes;
    for (int i = 0; i < v; i++) {
        vertexes.emplace_back();
    }

    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from;
        cin >> to;
        vertexes[from - 1].push_back(to);
        vertexes[to - 1].push_back(from);
    }

    //traps array
    int traps[v];
    for (int i = 0; i < v; i++) {
        cin >> traps[i];
    }

    //colors of vertexes array
    int colors[v];
    for (int i = 0; i < v; i++) {
        colors[i] = 0;
    }

    //do dfs from each vertex
    for (int i = 0; i < v; i++) {
        if (colors[i] == 0) {
            DFS_check_cycle(vertexes, colors, i, INT_MAX);
        }
    }

    cout << "NO";

    return 0;
}