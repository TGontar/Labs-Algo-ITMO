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
//using std::priority_queue;
//
////find the shortest way between current and each vertex
//void dijkstra(vector<vector<pair<int, int>>> &graph, priority_queue<pair<int, int>> &dist, int v, int start) {
//    vector<int> used(v, 0);
//
//    for (int i = 0; i < v; i++) {
//        pair<int, int> cur = dist.top();
//
//        //the vertex is not in current connectivity comp
//        if (cur.first == mx) {
//            break;
//        }
//
//        dist.pop()
//
//        for (auto e: graph[cur.second]) {
//            if (cur.first + e.second < dist[e.first]) {
//                dist[e.first] = dist[cur] + e.second;
//            }
//        }
//
//
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
//    priority_queue<pair<int, int>> dist;
//    for (int i = 0; i < v; i++) {
//        if (i == start-1) {
//            dist.push({0, i});
//        } else {
//            dist.push({mx, i});
//        }
//    }
//
//    dijkstra(vertexes, dist, v, start - 1);
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