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
////custom priority queue
//class CustumPriorQueue {
//private:
//    vector<pair<int, int>> arr{};
//    int n = 0;
//public:
//    //constructor for filling
//    CustumPriorQueue(int count, int val) {
//        for (int i = 0; i < count; i++) {
//            pushElem(val, i);
//        }
//        buildHeap();
//    }
//
//    //constructor for existing vector
//    CustumPriorQueue(vector<pair<int, int>> &vect) {
//        arr = vect;
//        n = (int)vect.size();
//        buildHeap();
//    }
//
//    void siftDown(int k) {
//        while (true) {
//            int tmp = k;
//            if (2 * k + 1 < n) {
//                if (arr[tmp].first > arr[2 * k + 1].first) {
//                    tmp = 2 * k + 1;
//                }
//            }
//            if (2 * k + 2 < n) {
//                if (arr[tmp].first > arr[2 * k + 2].first) {
//                    tmp = 2 * k + 2;
//                }
//            }
//            if (tmp != k) {
//                swap(arr[k], arr[tmp]);
//            } else {
//                break;
//            }
//            k = tmp;
//        }
//    }
//
//    void siftUp(int k) {
//        while (true) {
//            int tmp = k;
//            if ((k - 1) / 2 >= 0) {
//                if (arr[tmp].first < arr[(k - 1) / 2].first) {
//                    tmp = (k - 1) / 2;
//                }
//            }
//            if (tmp != k) {
//                swap(arr[k], arr[tmp]);
//            } else {
//                break;
//            }
//            k = tmp;
//        }
//    }
//
//
//    void buildHeap() {
//        for (int i = n / 2; i >= 0; i--) {
//            siftDown(i);
//        }
//
//    }
//
//    void pushElem(int d, int ver) {
//        arr.emplace_back(d, ver);
//        n += 1;
//        siftUp(n-1);
//    }
//
//    pair<int, int> extractMin() {
//        if (n == 0) {
//            return {mx, mx};
//        }
//        pair<int, int> ans = arr[0];
//        swap(arr[0], arr[n-1]);
//        arr.pop_back();
//        n -= 1;
//        siftDown(0);
//        return ans;
//    }
//
//    void decreaseKey(int x, int y) {
//        int change = 0;
//        for (int i = 0; i < n; i++) {
//            if (arr[i].second == x) {
//                change = i;
//                break;
//            }
//        }
//        arr[change].first = y;
//        siftUp(change);
//    }
//};
//
//
////find the shortest way between current and each vertex
//void dijkstra(vector<vector<pair<int, int>>> &graph, CustumPriorQueue &vert, vector<int> &dist, int v, int start) {
//    for (int i = 0; i < v; i++) {
//        pair<int, int> cur = vert.extractMin();
//
//        //the vertex is not in current connectivity comp
//        if (dist[cur.second] == mx) {
//            break;
//        }
//
//        for (auto e: graph[cur.second]) {
//            if (dist[cur.second] + e.second < dist[e.first]) {
//                dist[e.first] = dist[cur.second] + e.second;
//                vert.decreaseKey(e.first, dist[cur.second] + e.second);
//            }
//        }
//    }
//}
//
//
//int main() {
//    int v, e, q, start;
//    cin >> v;
//    cin >> e;
//    cin >> q;
//    cin >> start;
//
//    //create adjacency list
//    vector<vector<pair<int, int>>> vertexes;
//
//    for (int i = 0; i < v; i++) {
//        vertexes.emplace_back();
//    }
//
//    for (int i = 0; i < e; i++) {
//        int from, to, wight;
//        cin >> from;
//        cin >> to;
//        cin >> wight;
//        if (from != to) {
//            vertexes[from - 1].push_back({to - 1, wight});
//            vertexes[to - 1].push_back({from - 1, wight});
//        }
//    }
//
//    //find the shortest way between current and each vertex
//    CustumPriorQueue vert(v, mx);
//    vert.decreaseKey(start - 1, 0);
//
//    vector<int> dist(v, mx);
//    dist[start - 1] = 0;
//
//    dijkstra(vertexes, vert, dist, v, start - 1);
//
//    vector<int> answer;
//    for (int i = 0; i < q; i++) {
//        int finish;
//        cin >> finish;
//        if (finish > v or finish <= 0 or dist[finish - 1] == mx) {
//            answer.push_back(-1);
//        } else {
//            answer.push_back(dist[finish - 1]);
//        }
//    }
//
//    //print the answer
//    for (int i = 0; i < answer.size(); i++) {
//        cout << answer[i] << "\n";
//    }
//
//    return 0;
//}