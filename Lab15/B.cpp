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
//void DFS_mark_vertexes(vector<vector<int>> &graph, vector<vector<int>> &edges, vector<int> &colors, int cur, int prev, int time, vector<int> &enter, vector<int> &ret, set<int> &ans) {
//    time += 1;
//    enter[cur] = time;
//    ret[cur] = time;
//
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i];
//        if (colors[to] == 0) {
//            if (to == prev) {
//                continue;
//            }
//            if (enter[to] > 0) {
//                ret[cur] = min(ret[cur], enter[to]);
//            }
//            if (colors[to] == 0) {
//                DFS_mark_vertexes(graph, edges, colors, to, cur, time, enter, ret, ans);
//                ret[cur] = min(ret[cur], ret[to]);
//                if (ret[to] > ret[cur]) {
//                    for (auto ed: edges) {
//                        if (std::find(ed.begin(), ed.end() - 1, cur) != ed.end() and std::find(ed.begin(), ed.end() - 1, to) != ed.end()) {
//                            ans.insert(ed[3]);
//                            break;
//                        }
//                    }
//                }
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
//    int e;
//    cin >> e;
//
//
//    vector<vector<int>> edges;
//    vector<vector<int>> vertexes(v, vector<int>());
//    for (int i = 0; i < e; i++) {
//        int from, mid, to;
//        cin >> from;
//        cin >> mid;
//        cin >> to;
//        edges.push_back({from - 1, mid - 1, to - 1, i + 1});
//        vertexes[from - 1].push_back(mid - 1);
//        vertexes[mid - 1].push_back(from - 1);
//        vertexes[mid - 1].push_back(to - 1);
//        vertexes[to - 1].push_back(mid - 1);
//    }
//
//    vector<int> enter(v, 0);
//    vector<int> ret(v, 0);
//    int time = 0;
//    vector<int> colors(v, 0);
//    set<int> answer;
//    DFS_mark_vertexes(vertexes, edges, colors, 0, -1, time, enter, ret, answer);
//
//    cout << answer.size() << "\n";
//
//    for (auto i: answer) {
//        cout << i << " ";
//    }
//
//
//    return 0;
//}
