//#include "iostream"
//#include "algorithm"
//#include "vector"
//#include "queue"
//#include "stack"
//#include "set"
//
//#define mx 10000000
//
//using std::vector;
//using std::cin;
//using std::cout;
//using std::string;
//using std::queue;
//using std::stack;
//using std::swap;
//using std::set;
//using std::pair;
//using std::reverse;
//
////disjoint set union for graph
//class DSU {
//private:
//    vector<int> parent;
//    vector<int> size;
//    int n;
//public:
//    DSU(int count) {
//        n = count;
//        parent = vector<int>(n, 0);
//        for (int i = 0; i < n; i++) {
//            parent[i] = i;
//        }
//        size = vector<int>(n, 1);
//    }
//
//    void make_set(int v) {
//        parent[v] = v;
//        size[v] = 1;
//    }
//
//
//    int find_set(int v) {
//        if (v == parent[v])
//            return v;
//        return parent[v] = find_set(parent[v]);
//    }
//
//    void union_sets(int a, int b) {
//        a = find_set(a);
//        b = find_set(b);
//        if (a != b) {
//            if (size[a] < size[b])
//                swap(a, b);
//            parent[b] = a;
//            size[a] += size[b];
//        }
//    }
//
//};
//
//
//int main() {
//    int v, e, q;
//    cin >> v;
//    cin >> e;
//    cin >> q;
//
//    //create edges list
//    set<pair<int, int>> edges;
//    for (int i = 0; i < e; i++) {
//        int from, to;
//        cin >> from;
//        cin >> to;
//        edges.insert({from - 1, to - 1});
//    }
//
//    //requests
//    vector<vector<int>> requests;
//    for (int op = 0; op < q; op++) {
//        char temp;
//        int first, finish;
//        cin >> temp;
//        cin >> first;
//        cin >> finish;
//        first -= 1;
//        finish -= 1;
//
//        if (temp == '?') {
//            requests.push_back({1, first, finish});
//        } else {
//            requests.push_back({-1, first, finish});
//        }
//    }
//
//    //delete extra edges
//    for (int i = 0; i < requests.size(); i++) {
//        if (requests[i][0] == -1) {
//            edges.erase({requests[i][1], requests[i][2]});
//            edges.erase({requests[i][2], requests[i][1]});
//        }
//    }
//
//    //make a graph
//    DSU components = DSU(v);
//    for (auto i:edges) {
//        components.union_sets(i.first, i.second);
//    }
//
//    //make requests
//    vector<string> answer;
//    for (int i = (int)requests.size() - 1; i >= 0; i--) {
//        if (requests[i][0] == -1) {
//            components.union_sets(requests[i][1], requests[i][2]);
//        } else {
//            if (components.find_set(requests[i][1]) == components.find_set(requests[i][2])) {
//                answer.emplace_back("YES");
//            } else {
//                answer.emplace_back("NO");
//            }
//        }
//    }
//
//    reverse(answer.begin(), answer.end());
//
//    for (int i = 0; i < answer.size(); i++) {
//        cout << answer[i] << "\n";
//    }
//
//    return 0;
//
//}