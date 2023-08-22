//#include "iostream"
//#include "vector"
//#include "queue"
//#include "algorithm"
//
//#define mx 10000000
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
//using std::queue;
//using std::reverse;
//using std::pair;
//using std::min;
//using std::max;
//using std::swap;
//using std::endl;
//using std::min;
//
//
////change flow for inverted edge
//void change_backedge(vector<vector<vector<int>>> &graph, int from, int to, int delta) {
//    for (int i = 0; i < graph[to].size(); i++) {
//        if (graph[to][i][0] == from) {
//            graph[to][i][2] -= delta;
//            return;
//        }
//    }
//}
//
////find extra way from start to dest
//int dfs_ford_falkerson(vector<vector<vector<int>>> &graph, vector<int> &used, int t, int cur, int cmin) {;
//    if (cur == t) {
//        return cmin;
//    }
//    used[cur] = 1;
//
//    for (int i = 0; i < graph[cur].size(); i++) {
//        if (used[graph[cur][i][0]] == 0 and graph[cur][i][2] < graph[cur][i][1]) {
//            int delta = dfs_ford_falkerson(graph, used, t, graph[cur][i][0],
//                                           min(cmin, graph[cur][i][1] - graph[cur][i][2]));
//            if (delta > 0) {
//                graph[cur][i][2] += delta;
//                change_backedge(graph, cur, graph[cur][i][0], delta);
//                return delta;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int v, e;
//    cin >> v;
//    cin >> e;
//
//    if (v == 1) {
//        cout << 0;
//        exit(0);
//    }
//
//    //create adjacency list
//    vector<vector<vector<int>>> vertexes(v, vector<vector<int>>());
//
//    for (int i = 0; i < e; i++) {
//        int from, to, weight;
//        cin >> from;
//        cin >> to;
//        cin >> weight;
//        vertexes[from - 1].push_back({to - 1, weight, 0});
//        vertexes[to - 1].push_back({from - 1, weight, 0});
//    }
//
//    //find all extra ways
//    int ans = 0;
//    while (true) {
//        vector<int> used(v, 0);
//        int temp = dfs_ford_falkerson(vertexes, used, v - 1, 0, mx);
//        if (temp == 0) {
//            break;
//        } else {
//            ans += temp;
//        }
//    }
//
//    cout << ans;
//
//    return 0;
//}