/**
* @date: 2021-07-15
* @version: vol1
* @access: 쿼드트리와 비슷하지만 4개 대신 9개로 나누어 접근하였다.
* @weaknesses & learned:
*/
#include <iostream>
using namespace std;

const int MAX_N = 2187; // 행렬의 최대 크기: 3^7
int N;
int matrix[MAX_N][MAX_N];	// 행렬
int paperCount[3] = { 0,0,0 };	//[0]: -1로 이루어진 종이의 수, [1]: 0로 이루어진 종이의 수, [2]: 1로 이루어진 종이의 수

// 행렬 (y,x)에서부터 size 크기만큼의 행렬이 같은 숫자로 이루어져있는지 확인한다.
bool isSameNum(int y, int x, int size) {
	for (int _y = y; _y < y + size; ++_y)
		for (int _x = x; _x < x + size; ++_x)
			if (matrix[y][x] != matrix[_y][_x])
				return false;
	return true;
}

// 행렬 (y,x)에서부터 size크기의 행렬에서 나눌 수 있는 종이의 수를 게산한다.
void solve(int y, int x, int size) {
	if (isSameNum(y, x, size)) {
		paperCount[matrix[y][x] + 1]++;
		return;
	}

	int nextSize = size / 3;

	// 행렬을 3x3으로 나누어서 다시 계산
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			solve(y + i * nextSize, x + j * nextSize, nextSize);
		}
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> matrix[y][x];
	solve(0, 0, N);

	for (int i = 0; i < 3; ++i)
		cout << paperCount[i] << endl;
}