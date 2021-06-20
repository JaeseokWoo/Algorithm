#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_L = 300;
const int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
const int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int visited[MAX_L][MAX_L];
int l;
int sy, sx, fy, fx;

bool isRange(int y, int x) {
	return (y >= 0 && y < l&& x >= 0 && x < l);
}

int BFS() {
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	visited[sy][sx] = 0;
	q.push(make_pair(sy,sx));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isRange(ny, nx) && visited[ny][nx] == -1) {
				visited[ny][nx] = visited[y][x] + 1;
				if (ny == fy && nx == fx)
					return visited[ny][nx];
				q.push(make_pair(ny, nx));
			}
		}
	}
	return -1;
}

int main(void) {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> l;
		cin >> sy >> sx;
		cin >> fy >> fx;
		if (sy == fy && sx == fx)
			cout << 0 << endl;
		else cout << BFS() << endl;
	}
}