//#include "iostream"
//#include "vector"
//#include "queue"
//#include "algorithm"
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
//using std::queue;
//using std::reverse;
//
////traverse the graph via dfs
//void DFS_topo_sort(vector<vector<int>> &graph, int colors[], int cur, vector<int> &ans) {
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i];
//        if (colors[to] == 0) {
//            DFS_topo_sort(graph, colors, to, ans);
//        }
//    }
//    colors[cur] = 2;
//    ans.push_back(cur + 1);
//
//};
//
//int main() {
//    int v, e;
//    cin >> v;
//    cin >> e;
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
//    }
//
//    //colors of vertexes array
//    int colors[v];
//    for (int i = 0; i < v; i++) {
//        colors[i] = 0;
//    }
//
//    //sort the directed acyclic graph with top sort
//    vector<int> answer;
//    for (int i = 0; i < v; i++) {
//        if (colors[i] == 0) {
//            DFS_topo_sort(vertexes, colors, i, answer);
//        }
//    }
//    reverse(answer.begin(), answer.end());
//
//    //print the result
//    int finalanswer[v];
//    for (int i = 0; i < v; i++) {
//        finalanswer[answer[i] - 1] = i + 1;
//    }
//
//    for (int i = 0; i < v; i++) {
//        cout << finalanswer[i] << " ";
//    }
//
//    return 0;
//}