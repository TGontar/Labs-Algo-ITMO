#include <iostream>
#include <vector>
#include <algorithm>
#include "queue"

#define mx 10000000

using namespace std;

void DFS_mark_vertexes(vector<vector<int>>& graph, vector<int>& colors, vector<int>& enter, vector<int>& ret, vector<int>& parents, int cur, int prev, int& time, vector<pair<int, int>>& bridges, vector<int>& depths, int curdepth) {
    depths[cur] = curdepth;
    time++;
    enter[cur] = time;
    ret[cur] = time;
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (colors[to] == 0) {
            parents[to] = cur;
            DFS_mark_vertexes(graph, colors, enter, ret, parents, to, cur, time, bridges, depths, curdepth + 1);
            ret[cur] = min(ret[cur], ret[to]);
            if (ret[to] > enter[cur]) {
                bridges.push_back({ min(cur, to), max(cur, to) });
            }
        } else if (to != prev) {
            ret[cur] = min(ret[cur], enter[to]);
        }
    }
    colors[cur] = 2;
}

vector<int> bfs(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) {
            break;
        }

        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = cur;
            }
        }
    }

    vector<int> path;
    if (visited[end]) {
        int cur = end;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
    }

    return path;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> vertexes(v, vector<int>());
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        vertexes[from - 1].push_back(to - 1);
        vertexes[to - 1].push_back(from - 1);
    }

    int ans = 0;

    for (int i = 0; i < v; i++) {
        for (int j = i; j < v; j++) {
            vector<int> colors(v, 0);
            vector<int> enter(v, 0);
            vector<int> ret(v, 0);
            vector<int> parents(v, -1);
            vector<int> depths(v, 0);
            vector<pair<int, int>> bridges;
            int time = 0;

            DFS_mark_vertexes(vertexes, colors, enter, ret, parents, i, -1, time, bridges, depths, 1);

            vector<int> path = bfs(vertexes, i, j);

            for (auto br : bridges) {
                if (find(path.begin(), path.end(), br.first) != path.end() and find(path.begin(), path.end(), br.second) != path.end()) {
                    ans += 1;
                }
            }
        }
    }

    cout << ans;

    return 0;
}