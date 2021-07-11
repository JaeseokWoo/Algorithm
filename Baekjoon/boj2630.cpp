/**
* @date: 2021-07-11
* @version: vol1
* @access: 4개의 부분 문제로 나누는 쿼드트리 방식으로 해결하였다.
* @weaknesses & learned:
*/
#include <iostream>
using namespace std;

const int MAX_N = (1 << 7);
const int WHITE = 0;
const int BLUE = 1;
int N;
int paper[MAX_N][MAX_N];
int colors[2] = { 0,0 };

bool isSameColor(int y, int x, int size) {
	int color = paper[y][x];
	for (int _y = y; _y < y + size; ++_y) {
		for (int _x = x; _x < x + size; ++_x) {
			if (color != paper[_y][_x])
				return false;
		}
	}
	return true;
}

void solve(int y, int x, int size) {
	if (isSameColor(y, x, size)) {
		colors[paper[y][x]]++;
		return;
	}

	int half = size / 2;
	solve(y, x, half);
	solve(y, x + half, half);
	solve(y + half, x, half);
	solve(y + half, x + half, half);
}

int main() {
	int N;
	cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> paper[y][x];
	solve(0, 0, N);
	cout << colors[WHITE] << endl;
	cout << colors[BLUE] << endl;
}