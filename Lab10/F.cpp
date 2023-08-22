#include <iostream>
#include <vector>
#include <algorithm>

bool dfs(int v, std::vector <int> &color, std::vector<std::vector <int>> &adj, std::vector <int> &answer) {
    color[v] = 1;
    for (int u: adj[v]) {
        if (color[u] == 0) {
            dfs(u, color, adj, answer);
        }
    }
    color[v] = 2;
    answer.push_back(v+1);
    return false;
}

void topsort(int n, std::vector <std::vector <int>> &adj, std::vector <int> &color, std::vector <int> &answer) {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i, color, adj, answer);
        }
    }
    std::reverse(answer.begin(), answer.end());
}

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> color(n, 0);
    std::vector<int> answer(0);
    std::vector<int> final_answer(n);


    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    topsort(n, adj, color, answer);

    for (int i = 0; i < n; i++) {
        final_answer[answer[i]-1] = i+1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << final_answer[i] << " ";
    }
}