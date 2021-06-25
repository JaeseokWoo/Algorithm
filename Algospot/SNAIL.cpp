#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
double cache[MAX_M][MAX_N];

// days날 length미터일 때 M일까지 N미터까지 갈 확률을 반환한다.
double solve(int days, int length) {
	// 기저 사례: N미터 도달한 경우
	if (length >= N) return 1;
	// 기저 사례: days가 마지막 날인 경우
	if (days == M) return 0;

	double& ret = cache[days][length];
	if (ret != -1) return ret;
	ret = 0.75 * solve(days + 1, length + 2) + 0.25 * solve(days + 1, length + 1);
	return ret;
}

void init() {
	for (int i = 0; i < MAX_M; ++i)
		for (int j = 0; j < MAX_N; ++j)
			cache[i][j] = -1;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N >> M;
		init();
		printf("%.8lf\n", solve(0, 0));
	}
}
