#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 100;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int N, M;
string adj[MAX];

bool isRange(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	else if (adj[y][x] == '0')
		return false;
	else return true;
}

int BFS(int y, int x) {
	vector<int> visited(N * M, -1);
	visited[M * y + x] = 1;
	queue < pair<int, int>> q;
	q.push(make_pair(y, x));
	bool finised = false;

	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			if (isRange(nextY, nextX) && visited[M * nextY + nextX] == -1) {
				visited[M * nextY + nextX] = visited[M * hereY + hereX] + 1;
				if (nextY == N - 1 && nextX == M - 1) {
					finised = true;
					break;
				}
				q.push(make_pair(nextY, nextX));
			}
		}
		if (finised) break;
	}
	return visited[M * (N - 1) + M - 1];
}

int main(void) {
	cin >> N >> M;
	for (int n = 0; n < N; ++n)
		cin >> adj[n];
	cout << BFS(0, 0) << endl;
}