#include "iostream"
#include "vector"
#include "algorithm"

using std::vector;
using std::cin;
using std::cout;


//traverse the graph via dfs
void DFS_check_components(vector<vector<int>> &graph, int colors[], int cur, int prev) {
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (colors[to - 1] == 0) {
            if (to - 1 != prev) {
                DFS_check_components(graph, colors, to - 1, cur);
            }
        }
    }
    colors[cur] = 2;
};

//check if the tree is bamboo
bool check_bamboo(vector<vector<int>> &graph) {
    bool ans;

    //vector of vertexes' degrees
    vector<int> sizes;
    for (int i = 0; i < graph.size(); i++) {
        sizes.push_back(graph[i].size());
    }

    //the tree is bamboo, if there are 2 vertexes with degrees 1 and v-2 vertexes with degrees 2
    int degone = 0;
    int degtwo = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i] == 1) {
            degone += 1;
        } else if (sizes[i] == 2) {
            degtwo += 1;
        } else {
            continue;
        }
    }

    if (degone == 2 and degtwo == graph.size() - 2) {
        ans = true;
    } else {
        ans = false;
    }

    return ans;
}

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

    //colors of vertexes array
    int colors[v];
    for (int i = 0; i < v; i++) {
        colors[i] = 0;
    }

    //do dfs from each white vertex to count the components
    int countcomp = 0;
    for (int i = 0; i < v; i++) {
        if (colors[i] == 0) {
            countcomp += 1;
            DFS_check_components(vertexes, colors, i, INT_MAX);
        }
    }

    //check if the tree is bamboo and if there's only 1 conn. component
    if (check_bamboo(vertexes) and countcomp == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}