#include "iostream"
#include "vector"
#include "algorithm"

using std::vector;
using std::cin;
using std::cout;
using std::copy_n;
using std::pair;

//search for adjusted dots
void DFS_check(vector<vector<int>> &graph, int x, int y) {
    graph[x][y] = 0;
    if (graph[x - 1][y] == 1) {
        DFS_check(graph, x - 1, y);
    }
    if (graph[x][y + 1] == 1) {
        DFS_check(graph, x, y + 1);
    }
    if (graph[x + 1][y] == 1) {
        DFS_check(graph, x + 1, y);
    }
    if (graph[x][y - 1] == 1) {
        DFS_check(graph, x, y - 1);
    }
};


int main() {
    int n, m;
    cin >> n;
    cin >> m;

    //create matrix
    vector<vector<int>> rooms;
    for (int i = 0; i < n; i++) {
        rooms.emplace_back();
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == 46) { //char number for . symbol
                rooms[i].push_back(1);
            } else {
                rooms[i].push_back(0);
            }
        }
    }

    //check each dot in graph
    int answer = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (rooms[i][j] == 1) {
                answer += 1;
                DFS_check(rooms, i, j);
            }
        }
    }

    cout << answer;

    return 0;
}
