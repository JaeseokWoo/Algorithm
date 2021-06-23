#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 500 + 1;
int N;
int sequence[MAX_N];
int cache[MAX_N];

int solve(int index) {
	// 기저 사례: 마지막 index인 경우
	if (index == N) return 1;

	int& ret = cache[index];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = index + 1; i <= N; ++i) {
		if (sequence[index] < sequence[i])
			ret = max(ret, 1 + solve(i));
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		sequence[0] = 0;
		for (int n = 1; n <= N; ++n)
			cin >> sequence[n];
		memset(cache, -1, sizeof(cache));
		int ret = solve(0) - 1;
		cout << ret << endl;
	}
}