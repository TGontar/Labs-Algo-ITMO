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
//void
//DFS_mark_vertexes(vector<vector<int>> &graph, vector<int> &colors, vector<int> &heights, vector<int> &parents, int cur,
//                  int prev, int curheight) {
//    heights[cur] = curheight;
//    parents[cur] = prev + 1;
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i];
//        if (colors[to] == 0) {
//            if (to != prev) {
//                DFS_mark_vertexes(graph, colors, heights, parents, to, cur, curheight + 1);
//            }
//        }
//    }
//    colors[cur] = 2;
//};
//
//
//int main() {
//    int v;
//    cin >> v;
//    int e = v - 1;
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
//    vector<int> parents(v, mx);
//    vector<int> heights(v, mx);
//    vector<int> colors(v, 0);
//    DFS_mark_vertexes(vertexes, colors, heights, parents, 0, -1, 1);
//
//    for (int i = 0; i < v; i++) {
//        cout << heights[i] << " ";
//    } cout << "\n";
//
//    for (int i = 0; i < v; i++) {
//        cout << parents[i] << " ";
//    }
//
//
//
//    return 0;
//}
