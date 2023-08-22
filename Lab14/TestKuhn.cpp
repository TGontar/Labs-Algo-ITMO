//#include "iostream"
//#include "vector"
//
//using std::vector;
//using std::cin;
//using std::cout;
//
//
//bool try_kuhn(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &mt) {
//    if (used[v]) return false;
//    used[v] = true;
//    for (size_t i = 0; i < g[v].size(); ++i) {
//        int to = g[v][i];
//        if (mt[to] == -1 || try_kuhn(mt[to], g, used, mt)) {
//            mt[to] = v;
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> g(n + k, vector<int>());
//    vector<int> mt;
//    vector<bool> used;
//
//
//    int e;
//    cin >> e;
//    for (int i = 0; i < e; i++) {
//        int to, from;
//        cin >> to >> from;
//        g[to - 1].push_back(from - 1);
//        g[from - 1].push_back(to - 1);
//    }
//
//    mt.assign(n + k, -1);
//    for (int v = 0; v < n; ++v) {
//        used.assign(n + k, false);
//        try_kuhn(v, g, used, mt);
//        for (auto i : mt) {
//            cout << i + 1 << " ";
//        } cout << "\n";
//    }
//
//}