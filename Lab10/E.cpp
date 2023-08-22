//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//bool dfs(int v, std::vector <int> &color, std::vector<std::vector <int>> &adj, std::vector <int> &answer) {
//    color[v] = 1;
//    for (int u: adj[v]) {
//        if (color[u] == 0) {
//            dfs(u, color, adj, answer);
//        }
//    }
//    color[v] = 2;
//    answer.push_back(v+1);
//    return false;
//}
//
//void topsort(int n, std::vector <std::vector <int>> &adj, std::vector <int> &color, std::vector <int> &answer) {
//    for (int i = 0; i < n; i++) {
//        if (color[i] == 0) {
//            dfs(i, color, adj, answer);
//        }
//    }
//    std::reverse(answer.begin(), answer.end());
//}
//
//int main() {
//    int n, m, q;
//    std::cin >> n;
//    std::cin >> m;
//    std::cin >> q;
//    std::vector<int> color(n, 0);
//    std::vector <std::vector <int>> adj(n);
//    std::vector <std::vector <int>> adj_reversed(n);
//    std::vector<int> answer(0);
//
//    for (int i = 0; i < m; i++) {
//        int u, v;
//        std::cin >> u >> v;
//        u--, v--;
//        adj[u].push_back(v);
//        adj_reversed[v].push_back(u);
//    }
//
//    topsort(n, adj, color, answer);
//
//
////    for (int i = 0; i < q; i++) {
////        int x, y;
////        std::cin >> x;
////        std::cin >> y;
////        dfs(x-1, color, adj, x-1);
////        if (color[y-1] == 1) {
////            std::cout << "YES";
////        } else {
////            std::cout << "NO";
////        }
////        color.assign(color.size(), 0);
////    }
//
//    return 0;
//}
//
