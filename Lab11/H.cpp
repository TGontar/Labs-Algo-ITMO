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
//using std::swap;
//
//class DSU {
//private:
//    vector<int> parent;
//    vector<int> size;
//    int n;
//public:
//    DSU(int count) {
//        n = count;
//        parent = vector<int>(n, 0);
//        size = vector<int>(n, 0);
//    }
//
//    void make_set (int v) {
//        parent[v] = v;
//        size[v] = 1;
//    }
//
//
//    int find_set (int v) {
//        if (v == parent[v])
//            return v;
//        return parent[v] = find_set (parent[v]);
//    }
//
//    void union_sets (int a, int b) {
//        a = find_set(a);
//        b = find_set(b);
//        if (a != b) {
//            if (size[a] < size[b])
//                swap (a, b);
//            parent[b] = a;
//            size[a] += size[b];
//        }
//    }
//
//};
//
//
//
//int main() {
//    int n = 10;
//    DSU dsu1 = DSU(n);
//    dsu1.make_set(1);
//    dsu1.make_set(2);
//    dsu1.union_sets(1, 2);
//
//
//    return 0;
//}