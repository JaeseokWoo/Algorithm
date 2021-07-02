/**
* @date: 2021-07-02
* @version: vol1
* @access: dfs를 통해 네트워크 수를 계산하였다. 
* @weaknesses & learned:
*/
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 200;
int N;
vector<vector<int>> connected;
bool visited[MAX_N];

void init() {
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
        connected[i][i] = 0;
    }

}

void dfs(int here) {
    if (visited[here]) return;

    visited[here] = true;
    for (int next = 0; next < N; ++next) {
        if (!visited[next] && connected[here][next])
            dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    connected = computers;
    N = n;
    int answer = 0;

    init();
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}