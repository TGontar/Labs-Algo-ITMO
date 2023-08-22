//#include "iostream"
//#include "vector"
//#include "queue"
//#include "algorithm"
//
//#define mx 1000000
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
//using std::queue;
//using std::reverse;
//using std::pair;
//using std::distance;
//using std::find;
//
////find the shortest way between current and each vertex
//int algorithm_DAG(vector<vector<pair<int, int>>> &graph, vector<int> &top_sorted, int v, int start, int finish) {
//    vector<int> dist(v, mx);
//
//    dist[start] = 0;
//
//    //choose a vertex from which start
//    int starting = 0;
//    for (int i = 0; i < v; i++) {
//        if (top_sorted[i] == start) {
//            starting = i;
//            break;
//        }
//    }
//
//    for (int i = starting; i < v; i++) {
//        int cur = top_sorted[i];
//
//        for (auto e: graph[cur]) {
//            if (dist[cur] + e.second < dist[e.first]) {
//                dist[e.first] = dist[cur] + e.second;
//            }
//        }
//
//
//    }
//
//    return dist[finish];
//}
//
////traverse the graph via dfs
//void DFS_topo_sort(vector<vector<pair<int, int>>> &graph, int colors[], int cur, vector<int> &ans) {
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i].first;
//        if (colors[to] == 0) {
//            DFS_topo_sort(graph, colors, to, ans);
//        }
//    }
//    colors[cur] = 2;
//    ans.push_back(cur);
//};
//
//int main() {
//    int v, e;
//    cin >> v;
//    cin >> e;
//
//    int start, finish;
//    cin >> start;
//    cin >> finish;
//    start -= 1;
//    finish -= 1;
//
//    if (start == finish) {
//        cout << 0;
//        exit(0);
//    }
//
//    //create adjacency list
//    vector<vector<pair<int, int>>> vertexes(v, vector<pair<int, int>>());
//
//    for (int i = 0; i < e; i++) {
//        int from, to, wight;
//        cin >> from;
//        cin >> to;
//        cin >> wight;
//        vertexes[from - 1].push_back({to - 1, wight});
//    }
//
//
//    //colors of vertexes array
//    int colors[v];
//    for (int i = 0; i < v; i++) {
//        colors[i] = 0;
//    }
//
//    //sort the directed acyclic graph with top sort
//    vector<int> top_sorted;
//    for (int i = 0; i < v; i++) {
//        if (colors[i] == 0) {
//            DFS_topo_sort(vertexes, colors, i, top_sorted);
//        }
//    }
//    reverse(top_sorted.begin(), top_sorted.end());
//
//    int distance = algorithm_DAG(vertexes, top_sorted, v, start, finish);
//
//    if (distance >= mx) {
//        cout << -1;
//    } else {
//        cout << distance;
//    }
//
//
//    return 0;
//}