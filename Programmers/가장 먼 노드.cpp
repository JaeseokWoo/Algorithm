/**
* @date: 2021-07-06
* @version: vol1
* @access: bfs를 사용하여 가장 먼 거리를 구하여 접근하였다.
* @weaknesses & learned:
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
int N;

void makeGraph(const vector<vector<int>>& edge) {
    for (int i = 0; i < edge.size(); ++i) {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int bfs(int start) {
    discovered[start] = 0;
    queue<int> q;
    q.push(start);
    int ret = 0;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            if (discovered[there] == -1) {
                discovered[there] = discovered[here] + 1;
                ret = max(ret, discovered[there]);
                q.push(there);
            }
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    N = n + 1;
    adj = vector<vector<int>>(n + 1, vector<int>());
    discovered = vector<int>(n + 1, -1);
    makeGraph(edge);
    int longestDist = bfs(1);
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (discovered[i] == longestDist)
            answer++;
    }
    return answer;
}