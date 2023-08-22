#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

#define mx 10000000

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::queue;
using std::reverse;
using std::pair;
using std::min;
using std::max;

//find all distances in graph
vector<vector<int>> &floyd(vector<vector<int>> &graph, int v) {
    for (int mid = 0; mid < v; mid++) {
        for (int from = 0; from < v; from++) {
            for (int to = 0; to < v; to++) {
                graph[from][to] = min(graph[from][to], graph[from][mid] + graph[mid][to]);
            }
        }

    }

    return graph;
}

int main() {
    int v, e;
    cin >> v;
    cin >> e;

    //create adjacency matrix
    vector<vector<int>> matrix(v, vector<int>(v, mx));

    for (int i = 0; i < v; i++) {
        matrix[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int from, to, wight;
        cin >> from;
        cin >> to;
        cin >> wight;
        matrix[from - 1][to - 1] = wight;
        matrix[to - 1][from - 1] = wight;
    }

    matrix = floyd(matrix, v);

    //find minimum among all maximums
    pair<int, int> cnt = {0, mx};
    for (int i = 0; i < v; i++) {
        int maximum = 0;
        //find maximum among all paths from vertex
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] > maximum and matrix[i][j] != mx) {
                maximum = matrix[i][j];
            }
        }

        //if current maximum is less than total maximum
        if (maximum < cnt.second) {
            cnt = {i + 1, maximum};
        }

    }

    cout << cnt.first;

    return 0;
}
