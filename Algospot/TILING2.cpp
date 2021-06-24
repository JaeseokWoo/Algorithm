#include <iostream>
#include <cstring>
using namespace std;

const int M = 1000000007;
const int MAX_N = 100;
int N;
int cache[MAX_N];

// index를 덮을 차례일 때, 2*n 사각형을 덮을 수 있는 경우의 수
int solve(int index) {
	// 기저 사례: 모두 덮은 경우
	if (index == N) return 1;
	// 기저 사례: 범위를 벗어난 경우
	if (index > N) return 0;

	int& ret = cache[index];
	if (ret != -1) return ret;
	ret = 0;
	// 세로로 덮는 경우
	ret += solve(index + 1);
	ret %= M;
	// 가로로 덮는 경우
	ret += solve(index + 2);
	ret %= M;
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << solve(0) << endl;
	}
}