//#include "iostream"
//#include "vector"
//#include "queue"
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
//using std::queue;
//
////find if the way from cur to dest exists
//int BFS_find_shortest(vector<vector<int>> &graph, int v, int cur, int dest) {
//    if (cur == dest) {
//        return 0;
//    }
//
//    int *colors = new int[v]{};
//    int *dists = new int[v]{};
//
//    queue<int> q;
//    q.push(cur);
//    colors[cur] = 1;
//
//    while (!q.empty()) {
//        cur = q.front();
//        q.pop();
//        for (int i = 0; i < graph[cur].size(); i++) {
//            if (colors[graph[cur][i]] == 0) {
//                dists[graph[cur][i]] = 1;
//                q.push(graph[cur][i]);
//                colors[graph[cur][i]] = 1;
//            }
//        }
//    }
//
//    int ans = dists[dest];
//    delete[] dists;
//    delete[] colors;
//
//    if (ans == 0) {
//        return -1;
//    } else {
//        return ans;
//    }
//};
//
//
//int main() {
//    int v, e, q;
//    cin >> v;
//    cin >> e;
//    cin >> q;
//
//    //create adjacency list
//    vector<vector<int>> vertexes;
//    for (int i = 0; i < v; i++) {
//        vertexes.emplace_back();
//    }
//
//    for (int i = 0; i < e; i++) {
//        int from, to;
//        cin >> from;
//        cin >> to;
//        vertexes[from - 1].push_back(to - 1);
//        vertexes[to - 1].push_back(from - 1);
//    }
//
//    //colors of vertexes array
//    int colors[v];
//    for (int i = 0; i < v; i++) {
//        colors[i] = 0;
//    }
//
//    //do q operations
//    vector<string> ans;
//    for (int op = 0; op < q; op++) {
//        char temp;
//        cin >> temp;
//
//        if (temp == '?') {
//            int first, finish;
//            cin >> first;
//            cin >> finish;
//
//            //check if the path between first and finish exists
//            int pathexist = BFS_find_shortest(vertexes, v, first - 1, finish - 1);
//
//            if (pathexist == -1) {
//                ans.push_back("NO");
//            } else {
//                ans.push_back("YES");
//            }
//
//        } else {
//            int first, finish;
//            cin >> first;
//            cin >> finish;
//
//            //delete the edge
//            for (int i = 0; i < vertexes[first - 1].size(); i++) {
//                if (vertexes[first - 1][i] == finish - 1) {
//                    vertexes[first - 1].erase(vertexes[first - 1].begin() + i);
//                    break;
//                }
//            }
//
//            for (int i = 0; i < vertexes[finish - 1].size(); i++) {
//                if (vertexes[finish - 1][i] == first - 1) {
//                    vertexes[finish - 1].erase(vertexes[finish - 1].begin() + i);
//                    break;
//                }
//            }
//        }
//    }
//
//    //print the result
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//
//}