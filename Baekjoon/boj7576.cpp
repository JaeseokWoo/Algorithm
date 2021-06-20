#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1000;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int M, N;
int box[MAX][MAX];
int visited[MAX][MAX];

bool isRange(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}


int BFS() {
	queue<pair<int, int>> q;
	memset(visited, -1, sizeof(visited));
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x) {
			if (box[y][x] == 1) {
				q.push(make_pair(y, x));
				visited[y][x] = 0;
			}
			else if (box[y][x] == -1)
				visited[y][x] = 0;
		}

	int ret = 0;
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];
			if (isRange(nextY, nextX) && box[nextY][nextX] == 0 && visited[nextY][nextX] == -1) {
				q.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = visited[hereY][hereX] + 1;
				ret = max(ret, visited[nextY][nextX]);
			}
		}
	}
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			if (visited[y][x] == -1)
				return -1;
	return ret;

}

int main() {
	cin >> M >> N;
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			cin >> box[n][m];
	cout << BFS() << endl;
}