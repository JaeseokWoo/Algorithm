#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
const int dz[2] = { 1,-1 };
int M, N, H; // 가로, 세로, 높이
int box[MAX][MAX][MAX];
int unripe;
typedef struct {
	int z, y, x;
} tomato;


bool isRange(int z, int y, int x) {
	return (z >= 0 && z < H&& y >= 0 && y < N&& x >= 0 && x < M);
}

int BFS() {
	queue<tomato> q;
	for (int z = 0; z < H; ++z)
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x)
				if (box[z][y][x] == 1)
					q.push({ z,y,x });
	int ripe = 0;
	int day = 0;
	while (!q.empty()) {
		int cz = q.front().z;
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int i = 0; i < 2; ++i) {
			int nz = cz + dz[i];
			if (isRange(nz, cy, cx) && box[nz][cy][cx] == 0) {
				box[nz][cy][cx] = box[cz][cy][cx] + 1;
				ripe++;
				day = max(day, box[nz][cy][cx]);
				q.push({ nz,cy,cx });
			}
		}
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (isRange(cz, ny, nx) && box[cz][ny][nx] == 0) {
				box[cz][ny][nx] = box[cz][cy][cx] + 1;
				ripe++;
				day = max(day, box[cz][ny][nx]);
				q.push({ cz,ny,nx });
			}
		}
	}
	if (unripe == ripe)
		return day - 1;
	else return -1;
}

int main(void) {
	cin >> M >> N >> H;
	unripe = 0;
	for (int z = 0; z < H; ++z)
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x) {
				cin >> box[z][y][x];
				if (box[z][y][x] == 0)
					unripe++;
			}
	if (unripe == 0)
		cout << 0 << endl;
	else cout << BFS() << endl;
}