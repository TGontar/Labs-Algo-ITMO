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

//choose the vertex to enter next
vector<pair<int, int>> choose_to(vector<vector<int>> &graph, int n, int m, int cury, int curx) {
    vector<pair<int, int>> ans;
    if (curx != 0 and graph[cury][curx - 1] != mx) {
        ans.push_back({cury, curx - 1});
    }
    if (cury != 0 and graph[cury - 1][curx] != mx) {
        ans.push_back({cury - 1, curx});
    }
    if (curx != (m - 1) and graph[cury][curx + 1] != mx) {
        ans.push_back({cury, curx + 1});
    }
    if (cury != (n - 1) and graph[cury + 1][curx] != mx) {
        ans.push_back({cury + 1, curx});
    }

    return ans;
}

//kuhn algo for max matching
bool dfs_kuhn (vector<vector<int>> &graph, vector<vector<int>> &used, vector<vector<pair<int, int>>> &matching, int n, int m, int cury, int curx) {
    if (used[cury][curx] == 1) {
        return false;
    }
    used[cury][curx] = 1;

    vector<pair<int, int>> tos = choose_to(graph, n, m, cury, curx);
    for (auto i:tos) {
        if (matching[i.first][i.second] == pair<int, int>{-1, -1} or dfs_kuhn(graph, used, matching, n, m, matching[i.first][i.second].first, matching[i.first][i.second].second)) {
            matching[i.first][i.second] = {cury, curx};
            return true;
        }
    }

    return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n;
    cin >> m;
    cin >> q;

    //create adjacency matrix
    vector<vector<int>> matrix (n, vector<int>(m, 1));

    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from;
        cin >> to;
        matrix[from - 1][to - 1] = mx;
    }


    //do dfs for each vertex
    vector<vector<pair<int, int>>> matching(n, vector<pair<int, int>>(m, {-1, -1}));
    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != mx) {
                vector<vector<int>> used(n, vector<int>(m, 0));
                dfs_kuhn(matrix, used, matching, n, m, i, j);
            }
        }
    }

    int ans = 0;
    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matching[i][j] != pair<int, int>{-1, -1}) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}