#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"


using std::vector;
using std::cin;
using std::cout;
using std::copy_n;
using std::queue;

//find the shortest way from cur to dest
int BFS_find_shortest(vector<vector<int>> &graph, int colors[], int v, int cur, int dest) {
    int *dists = new int[v];
    for (int k = 0; k < v; k++) {
        dists[k] = 0;
    }
    queue<int> q;
    q.push(cur);
    colors[cur] = 1;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (colors[graph[cur][i] - 1] == 0) {
                dists[graph[cur][i] - 1] = dists[cur] + 1;
                q.push(graph[cur][i] - 1);
                colors[graph[cur][i] - 1] = 1;
            }
        }
    }

    return dists[dest];
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

    //colors of vertexes array
    int colors[v];
    for (int i = 0; i < v; i++) {
        colors[i] = 0;
    }

    //from and dest vertexes
    int s, f;
    cin >> s;
    cin >> f;

    int answer = BFS_find_shortest(vertexes, colors, v, s - 1, f - 1);
    if (answer == 0) {
        cout << "-1";
    } else {
        cout << answer;
    }

    return 0;
}