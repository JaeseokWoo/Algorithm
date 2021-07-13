/**
* @date: 2021-07-13
* @version: vol1
* @access: 매번 압축할 수 있는지 확인하여 압축할 수 있을 경우 압축하고 못 하면 크기를 반으로 줄여 쿼드트리 기반으로 수행하는 함수를 구현하여 문제에 접근하였다.
* @weaknesses & learned:
	1. isCompressed()함수를 구현할 때 반복문 구간을 _y, _x 둘 다 0부터 시작하게 두는 실수로 디버그하는데 시간을 소비하였다.
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 64;
int N;
char image[MAX_N][MAX_N];

bool isCompressed(int y, int x, int size) {
	char color = image[y][x];
	for (int _y = y; _y < y + size; ++_y)
		for (int _x = x; _x < x + size; ++_x)
			if (image[_y][_x] != color)
				return false;
	return true;
}

string solve(int y, int x, int size) {
	// 압축 가능하면 압축한다.
	if (isCompressed(y, x, size))
		return string(1, image[y][x]);

	int half = size / 2;
	string ret = "(";
	ret += solve(y, x, half);	//왼쪽 위
	ret += solve(y, x + half, half);	// 오른쪽 위
	ret += solve(y + half, x, half);	//왼쪽 아래
	ret += solve(y + half, x + half, half);	//오른쪽 아래
	ret += ")";
	return ret;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x)
			cin >> image[y][x];
	}
	cout << solve(0, 0, N) << endl;
}