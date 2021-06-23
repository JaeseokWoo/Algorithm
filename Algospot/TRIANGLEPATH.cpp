#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100;
int N;
int triangle[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int solve(int y, int x) {
	// 기저 사례: 범위를 벗어난 경우
	if (y < 0 || y >= N || x < 0 || x >= N) return 0;
	
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + triangle[y][x];
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		for (int n = 0; n < N; ++n)
			for (int i = 0; i < n + 1; ++i)
				cin >> triangle[n][i];
		memset(cache, -1, sizeof(cache));
		int ret = solve(0, 0);
		cout << ret << endl;
	}
}