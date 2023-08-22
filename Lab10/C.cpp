#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::queue;
using std::reverse;

//traverse the graph via dfs
void DFS_topo_sort(vector<vector<int>> &graph, int colors[], int cur, vector<int> &ans) {
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (colors[to] == 0) {
            DFS_topo_sort(graph, colors, to, ans);
        }
    }
    colors[cur] = 2;
    ans.push_back(cur + 1);
};

//find connectivity components
void DFS_find_components(vector<vector<int>> &graph, int comp[], int colors[], int cur, int curcomp) {
    comp[cur] = curcomp;
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (colors[to] == 0) {
            DFS_find_components(graph, comp, colors, to, curcomp);
        }
    }
    colors[cur] = 2;
};


int main() {
    int v, e, q;
    cin >> v;
    cin >> e;
    cin >> q;

    //create adjacency list
    vector<vector<int>> vertexes;
    vector<vector<int>> invvertexes;

    for (int i = 0; i < v; i++) {
        vertexes.emplace_back();
        invvertexes.emplace_back();
    }

    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from;
        cin >> to;
        vertexes[from - 1].push_back(to - 1);
        invvertexes[to - 1].push_back(from - 1);
    }

    //colors of vertexes array
    int colors[v];
    for (int i = 0; i < v; i++) {
        colors[i] = 0;
    }

    //sort the directed acyclic graph with top sort
    vector<int> answer;
    for (int i = 0; i < v; i++) {
        if (colors[i] == 0) {
            DFS_topo_sort(vertexes, colors, i, answer);
        }
    }
    reverse(answer.begin(), answer.end());

    //find the components of strong connectivity
    int components[v];
    int countcomps = 0;

    for (int i = 0; i < v; i++) {
        colors[i] = 0;
    }

    for (int i = 0; i < v; i++) {
        if (colors[answer[i] - 1] == 0) {
            countcomps += 1;
            DFS_find_components(invvertexes, components, colors, answer[i] - 1, countcomps);
        }
    }

    //do checks
    vector<string> finalans;
    for (int i = 0; i < q; i++) {
        int start, finish;
        cin >> start;
        cin >> finish;

        if (components[start - 1] == components[finish - 1]) {
            finalans.push_back("YES");
        } else {
            finalans.push_back("NO");
        }
    }

    //print the result
    for (int i = 0; i < finalans.size(); i++) {
        cout << finalans[i] << "\n";
    }

    return 0;
}