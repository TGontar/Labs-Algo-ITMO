//#include "iostream"
//#include "vector"
//#include "queue"
//#include "algorithm"
//#include "set"
//
//#define mx 10000000
//
//using namespace std;
//
//
////mark edges with dfs - inorder traversal of the tree
//void DFS_mark_vertexes(vector<vector<int>> &graph, vector<int> &colors, int cur, int prev, vector<vector<int>> &comps, int curcomp) {
//    comps[curcomp].push_back(cur + 1);
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i];
//        if (colors[to] == 0) {
//            if (to != prev) {
//                DFS_mark_vertexes(graph, colors, to, cur, comps, curcomp);
//            }
//        }
//    }
//    colors[cur] = 2;
//};
//
//
//int main() {
//    int v, e;
//    cin >> v >> e;
//
//    vector<vector<int>> vertexes(v, vector<int>());
//    for (int i = 0; i < e; i++) {
//        int from, to;
//        cin >> from;
//        cin >> to;
//        vertexes[from - 1].push_back(to - 1);
//        vertexes[to - 1].push_back(from - 1);
//    }
//
//
//    vector<int> colors(v, 0);
//    vector<vector<int>> comps;
//    int cnt = 0;
//    for (int i = 0; i < v; i++) {
//        if (colors[i] == 0) {
//            cnt += 1;
//            comps.emplace_back();
//            DFS_mark_vertexes(vertexes, colors,  i, -1, comps, cnt - 1);
//        }
//    }
//
//    cout << comps.size() << "\n";
//
//    for (int i = 0; i < comps.size(); i++) {
//        cout << comps[i].size() << "\n";
//        sort(comps[i].begin(), comps[i].end());
//        for (auto j:comps[i]) {
//            cout << j << " ";
//        } cout << "\n";
//    }
//
//
//
//    return 0;
//}
