//#include "iostream"
//#include "vector"
//#include "algorithm"
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::copy_n;
//using std::pair;
//
////search for adjusted dots
//void DFS_check(vector<vector<int>> &graph, int n, int m, int x, int y) {
//    graph[x][y] = 0;
//    if (x > 0 and graph[x - 1][y] == 1) {
//        DFS_check(graph, n, m, x - 1, y);
//    }
//    if (y < m - 1 and graph[x][y + 1] == 1) {
//        DFS_check(graph, n, m, x, y + 1);
//    }
//    if (x < n - 1 and graph[x + 1][y] == 1) {
//        DFS_check(graph, n, m, x + 1, y);
//    }
//    if (y > 0 and graph[x][y - 1] == 1) {
//        DFS_check(graph, n, m, x, y - 1);
//    }
//};
//
//
//int main() {
//    int n, m;
//    cin >> n;
//    cin >> m;
//
//    //create matrix
//    vector<vector<int>> rooms;
//    for (int i = 0; i < n; i++) {
//        rooms.emplace_back();
//        for (int j = 0; j < m; j++) {
//            char tmp;
//            cin >> tmp;
//            if (tmp == 43) { //char number for + symbol
//                rooms[i].push_back(1);
//            } else {
//                rooms[i].push_back(0);
//            }
//        }
//    }
//
//    //check each dot in graph
//    int answer = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (rooms[i][j] == 1) {
//                answer += 1;
//                DFS_check(rooms, n, m, i, j);
//            }
//        }
//    }
//
//    cout << answer;
//
//    return 0;
//}
