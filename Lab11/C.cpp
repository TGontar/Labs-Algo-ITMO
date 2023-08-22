//#include "iostream"
//#include "vector"
//#include "queue"
//#include "algorithm"
//
//#define mx 100000000
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
//int bellman_ford_cycles(vector<vector<int>> &graph, int v, int start) {
//    vector<int> dists(v, mx);
//    vector<int> prev(v, -1);
//    dists[start] = 0;
//
//    for (int i = 0; i < v - 1; i++) {
//        int check = 0;
//        for (auto j: graph) {
//            if (dists[j[0]] + j[2] < dists[j[1]]) {
//                dists[j[1]] = dists[j[0]] + j[2];
//                prev[j[1]] = j[0];
//                check += 1;
//            }
//        }
//
//        if (check == 0) {
//            break;
//        }
//    }
//
//    int cnt = 0;
//    for (auto j: graph) {
//        if (dists[j[0]] + j[2] < dists[j[1]]) {
//            prev[j[1]] = j[0];
//            int cur = j[1];
//            for (int i = 0; i < v - 1; i++) {
//                cur = prev[cur];
//            }
//            int u = cur;
//            while (u != prev[cur]) {
//                cnt += 1;
//                cur = prev[cur];
//            }
//            cnt += 1;
//
//            break;
//        }
//    }
//
//    return cnt;
//}
//
//int main() {
//    int q, k;
//    cin >> q;
//    cin >> k;
//
//    vector<string> ans;
//    for (int query = 0; query < q; query++) {
//        int v, e;
//        cin >> v;
//        cin >> e;
//
//        //create list of edges
//        vector<vector<int>> edges;
//
//        for (int i = 0; i < e; i++) {
//            int from, to, wight;
//            cin >> from;
//            cin >> to;
//            cin >> wight;
//            edges.push_back({from - 1, to - 1, wight});
//        }
//
//        //do the check
//        if (bellman_ford_cycles(edges, v, 0) > k) {
//            ans.emplace_back("NO");
//        } else {
//            ans.emplace_back("YES");
//        }
//
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}