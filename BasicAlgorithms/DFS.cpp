#include "iostream"
#include "vector"
#include "stack"

using std::vector;
using std::cin;
using std::cout;
using std::stack;

void DFS(vector<vector<int>> &graph, int colors[], int cur) {
    colors[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (colors[i] == 0) {
            DFS(graph, colors, i);
        }
        colors[cur] = 2;
    }
};


int main() {
    int n;
    cin >> n;

    vector<vector<int>> verticles;
    int colors[n];
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        for (int j = 1; j <= i; j++) {
            temp.push_back(j);
        }
        verticles.push_back(temp);
    }

    DFS(verticles, colors, 0);

    for (int i = 0; i < verticles.size(); i++) {
        for (int j = 0; j < verticles[i].size(); j++) {
            cout << verticles[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}