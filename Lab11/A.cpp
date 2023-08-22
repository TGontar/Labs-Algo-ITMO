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
//
//vector<vector<int>> &floyd(vector<vector<int>> &graph, int v, int k) {
//    for (int mid = 0; mid < v; mid++) {
//        for (int from = 0; from < v; from++) {
//            for (int to = 0; to < v; to++) {
//                if (abs(mid - from) <= k and  abs(to - mid) <= k)
//                graph[from][to] = min(graph[from][to], graph[from][mid] + graph[mid][to]);
//            }
//        }
//
//    }
//
//    return graph;
//}
//
//
//int main() {
//    int v, e, k;
//    cin >> v;
//    cin >> e;
//    cin >> k;
//
//    //create adjacency matrix
//    vector<vector<int>> matrix(v, vector<int>(v, mx));
//
//    for (int i = 0; i < v; i++) {
//        matrix[i][i] = 0;
//    }
//
//    for (int i = 0; i < e; i++) {
//        int from, to, wight;
//        cin >> from;
//        cin >> to;
//        cin >> wight;
//        matrix[from - 1][to - 1] = wight;
//    }
//
//    //find all shortest ways
//    matrix = floyd(matrix, v, k);
//
//    //queries
//    int q;
//    cin >> q;
//
//    vector<int> ans;
//    for (int i = 0; i < q; i++) {
//        int from, to;
//        cin >> from;
//        cin >> to;
//
//        //check the condition
//        if (matrix[from - 1][to - 1] < mx) {
//            ans.push_back(matrix[from - 1][to - 1] );
//        } else {
//            ans.push_back(-1);
//        }
//    }
//
//    //print the answer
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}