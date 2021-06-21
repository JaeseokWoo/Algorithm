#include <iostream>
using namespace std;

int H, W;
char board[20][20];
const int L[4][2][2] = {
	{{1,0},{1,-1}},
	{{1,0},{1,1}},
	{{0,1},{1,1}},
	{{0,1},{1,0}}
};

bool isPossible(int y, int x, int k) {
	for (int i = 0; i < 2; ++i) {
		int ny = y + L[k][i][0];
		int nx = x + L[k][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) return false;
		if (board[ny][nx] == '#') return false;
	}
	return true;
}

void fill(int y, int x, int k) {
	board[y][x] = '#';
	for (int i = 0; i < 2; ++i) {
		int ny = y + L[k][i][0];
		int nx = x + L[k][i][1];
		board[ny][nx] = '#';

	}
}

void notFill(int y, int x, int k) {
	board[y][x] = '.';
	for (int i = 0; i < 2; ++i) {
		int ny = y + L[k][i][0];
		int nx = x + L[k][i][1];
		board[ny][nx] = '.';

	}
}

int solve() {
	int h, w;
	bool ok = true;

	for (h = 0; h < H; ++h) {
		for (w = 0; w < W; ++w) {
			if (board[h][w] == '.') {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}

	if (ok) return 1;
	int ret = 0;
	for (int k = 0; k < 4; ++k) {
		if (isPossible(h, w, k)) {
			fill(h, w, k);
			ret += solve();
			notFill(h, w, k);
		}
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> H >> W;
		int white = 0;
		for (int h = 0; h < H; ++h)
			for (int w = 0; w < W; ++w) {
				cin >> board[h][w];
				if (board[h][w] == '.')
					white++;
			}
		int ret = 0;
		if (white % 3 == 0) ret = solve();
		cout << ret << endl;
	}
}