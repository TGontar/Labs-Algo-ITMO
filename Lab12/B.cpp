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
//using std::swap;
//using std::endl;
//
////disjolong long set union for graph
//class DSU {
//private:
//    vector<long long> parent;
//    vector<long long> size;
//    long long n;
//    long long diff;
//public:
//    DSU(long long count) {
//        n = count;
//        diff = count;
//        parent = vector<long long>(n, 0);
//        for (long long i = 0; i < n; i++) {
//            parent[i] = i;
//        }
//        size = vector<long long>(n, 1);
//    }
//
//    void make_set(long long v) {
//        parent[v] = v;
//        size[v] = 1;
//    }
//
//
//    long long find_set(long long v) {
//        if (v == parent[v])
//            return v;
//        return parent[v] = find_set(parent[v]);
//    }
//
//    void union_sets(long long a, long long b) {
//        a = find_set(a);
//        b = find_set(b);
//        if (a != b) {
//            if (size[a] < size[b])
//                swap(a, b);
//            parent[b] = a;
//            size[a] += size[b];
//            diff -= size[b];
//        }
//    }
//
//    //check if the mst is completed
//    bool check_if_one_comp () {
//        return (diff == 1 or diff == 0);
//    }
//
//};
//
////quicksort for edges list
//void quick_sort(vector<vector<long long>> &arr, long long l, long long r) {
//    long long i = l;
//    long long j = r;
//    long long x = arr[(l + r) / 2][2];
//    while (i <= j) {
//        while (arr[i][2] < x) {
//            i++;
//        }
//        while (arr[j][2] > x) {
//            j--;
//        }
//        if (i <= j) {
//            std::swap(arr[i], arr[j]);
//            i++;
//            j--;
//        }
//    }
//    if (l < j) {
//        quick_sort(arr, l, j);
//    }
//    if (i < r) {
//        quick_sort(arr, i, r);
//    }
//}
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    long long v, e;
//    cin >> v;
//    cin >> e;
//
//    //create edges list
//    vector<vector<long long>> edges;
//
//    for (long long i = 0; i < e; i++) {
//        long long from, to, weight;
//        cin >> from;
//        cin >> to;
//        cin >> weight;
//        edges.push_back({from - 1, to - 1, weight});
//    }
//
//    //sort the edges list
//    quick_sort(edges, 0, edges.size() - 1);
//
//    //components of connectivity
//    DSU comps = DSU(v);
//
//    //check each edge if it makes a cycle after adding
//    long long ans = 0;
//    for (auto i:edges) {
//        if (comps.find_set(i[0]) != comps.find_set(i[1])) {
//            comps.union_sets(i[0], i[1]);
//            ans += i[2];
//        }
//
//        if (comps.check_if_one_comp()) {
//            break;
//        }
//    }
//
//    cout << ans;
//
//
//    return 0;
//}