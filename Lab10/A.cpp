//#include "iostream"
//#include "vector"
//#include "algorithm"
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::copy_n;
//
////traverse the graph via dfs
//void DFS_check_components(vector<vector<int>> &graph, int comps[], int colors[], int cur, int curcomp) {
//    comps[cur] = curcomp;
//    colors[cur] = 1;
//    for (int i = 0; i < graph[cur].size(); i++) {
//        int to = graph[cur][i];
//        if (colors[to] == 0) {
//            DFS_check_components(graph, comps, colors, to, curcomp);
//        }
//    }
//    colors[cur] = 2;
//};
//
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
//        vertexes[to - 1].push_back(from - 1);
//    }
//
//    //traps array
//    int traps[v];
//    for (int i = 0; i < v; i++) {
//        cin >> traps[i];
//    }
//
//    //colors of vertexes array
//    int colors[v];
//    for (int i = 0; i < v; i++) {
//        colors[i] = 0;
//    }
//
//    //components of connectivity array
//    int components[v];
//    for (int i = 0; i < v; i++) {
//        components[i] = 0;
//    }
//
//    //do DFS from each vertex
//    int countcomp = 0;
//    for (int i = 0; i < v; i++) {
//        if (colors[i] == 0) {
//            countcomp += 1;
//            DFS_check_components(vertexes, components, colors, i, countcomp);
//        }
//    }
//
//    //check the traps
//    int trapcomps[countcomp];
//    for (int i = 0; i < countcomp; i++) {
//        trapcomps[i] = 0;
//    }
//
//    for (int i = 0; i < v; i++) {
//        if (traps[i] == 1) {
//            trapcomps[components[i] - 1] = 1;
//        }
//    }
//
//    //print components and traps
//    cout << countcomp << "\n";
//
//    for (int i = 0; i < v; i++) {
//        cout << components[i] << " ";
//    } cout << "\n";
//
//    for (int i = 0; i < countcomp; i++) {
//        cout << trapcomps[i] << " ";
//    } cout << "\n";
//
//    return 0;
//}