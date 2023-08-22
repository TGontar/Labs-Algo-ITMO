#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using std::vector;
using std::cin;
using std::cout;
using std::copy_n;
using std::queue;

//find the shortest way from cur to dest
int BFS_find_shortest(vector<vector<vector<int>>> &graph, vector<vector<vector<int>>> &colors, vector<int> &cur,
                      vector<int> &dest) {

    //make a 3-d vector of distances from cur vertex to all others
    vector<vector<vector<int>>> dists;
    for (int i = 0; i < 101; i++) {
        dists.emplace_back();
        for (int j = 0; j < 101; j++) {
            dists[i].emplace_back();
            for (int k = 0; k < 101; k++) {
                dists[i][j].push_back(0);
            }
        }
    }

    //init a queue of vectors
    queue<vector<int>> q;
    q.push(cur);
    colors[cur[0]][cur[1]][cur[2]] = 1;

    //check all the adjacent vertexes
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur == dest) {
            break;
        }
        if (cur[0] - 1 >= 0 and graph[cur[0] - 1][cur[1]][cur[2]] == 1 and colors[cur[0] - 1][cur[1]][cur[2]] == 0) {
            q.push({cur[0] - 1, cur[1], cur[2]});
            dists[cur[0] - 1][cur[1]][cur[2]] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0] - 1][cur[1]][cur[2]] = 1;
        }
        if (cur[0] + 1 <= 100 and graph[cur[0] + 1][cur[1]][cur[2]] == 1 and colors[cur[0] + 1][cur[1]][cur[2]] == 0) {
            q.push({cur[0] + 1, cur[1], cur[2]});
            dists[cur[0] + 1][cur[1]][cur[2]] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0] + 1][cur[1]][cur[2]] = 1;
        }
        if (cur[1] - 1 >= 0 and graph[cur[0]][cur[1] - 1][cur[2]] == 1 and colors[cur[0]][cur[1] - 1][cur[2]] == 0) {
            q.push({cur[0], cur[1] - 1, cur[2]});
            dists[cur[0]][cur[1] - 1][cur[2]] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0]][cur[1] - 1][cur[2]] = 1;
        }
        if (cur[1] + 1 <= 100 and graph[cur[0]][cur[1] + 1][cur[2]] == 1 and colors[cur[0]][cur[1] + 1][cur[2]] == 0) {
            q.push({cur[0], cur[1] + 1, cur[2]});
            dists[cur[0]][cur[1] + 1][cur[2]] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0]][cur[1] + 1][cur[2]] = 1;
        }
        if (cur[2] - 1 >= 0 and graph[cur[0]][cur[1]][cur[2] - 1] == 1 and colors[cur[0]][cur[1]][cur[2] - 1] == 0) {
            q.push({cur[0], cur[1], cur[2] - 1});
            dists[cur[0]][cur[1]][cur[2] - 1] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0]][cur[1]][cur[2] - 1] = 1;
        }
        if (cur[2] + 1 <= 100 and graph[cur[0]][cur[1]][cur[2] + 1] == 1 and colors[cur[0]][cur[1]][cur[2] + 1] == 0) {
            q.push({cur[0], cur[1], cur[2] + 1});
            dists[cur[0]][cur[1]][cur[2] + 1] = dists[cur[0]][cur[1]][cur[2]] + 1;
            colors[cur[0]][cur[1]][cur[2] + 1] = 1;
        }
    }

    return dists[dest[0]][dest[1]][dest[2]];
};


int main() {
    int countb, energy;
    cin >> countb;
    cin >> energy;

    //start and finish
    vector<int> start;
    vector<int> finish;

    for (int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        start.push_back(tmp);
    }

    for (int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        finish.push_back(tmp);
    }

    //buildings
    vector<vector<int>> buildings;
    for (int i = 0; i < countb; i++) {
        buildings.emplace_back();
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            buildings[i].push_back(temp);
        }
    }

    //matrix of space
    vector<vector<vector<int>>> space;
    for (int i = 0; i < 101; i++) {
        space.emplace_back();
        for (int j = 0; j < 101; j++) {
            space[i].emplace_back();
            for (int k = 0; k < 101; k++) {
                space[i][j].push_back(1);
            }
        }
    }

    for (int i = 0; i < buildings.size(); i++) {
        for (int j = 0; j < buildings[i][3]; j++) {
            space[buildings[i][0]][buildings[i][1]][buildings[i][2] + j] = 0;
        }
    }

    //fast check
    if (start == finish) {
        cout << 0;
        exit(0);
    } else if (space[start[0]][start[1]][start[2]] == 0 or space[finish[0]][finish[1]][finish[2]] == 0) {
        cout << -1;
        exit(0);
    }

    //3-d vector of colors, 0 is white and 1 is black
    vector<vector<vector<int>>> colors;
    for (int i = 0; i < 101; i++) {
        colors.emplace_back();
        for (int j = 0; j < 101; j++) {
            colors[i].emplace_back();
            for (int k = 0; k < 101; k++) {
                colors[i][j].push_back(0);
            }
        }
    }

    int answer = BFS_find_shortest(space, colors, start, finish);

    if (answer <= energy and answer != 0) {
        cout << answer;
    } else {
        cout << -1;
    }



    return 0;
}
