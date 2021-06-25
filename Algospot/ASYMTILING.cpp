#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 100 + 1;
int N;
int cache[MAX_N];
int synCache[MAX_N];

int tiling(int width) {
	//기저 사례
	if (width <= 1) return 1;

	int& ret = cache[width];
	if (ret != -1) return ret;

	ret = tiling(width - 1) + tiling(width - 2);
	ret %= MOD;
	return ret;
}

int synTiling(int width) {
	// 기저 사례
	if (width <= 1) return 1;
	if (width == 2) return 2;
	if (width == 3) return 1;

	int& ret = synCache[width];
	if (ret != -1) return ret;
	ret = synTiling(width - 2) + synTiling(width - 4);
	ret %= MOD;

	return ret;
}

int solve(int width) {
	int ret = tiling(width) - synTiling(width);
	ret += MOD;
	ret %= MOD;
	return ret;
}

void init() {
	memset(cache, -1, sizeof(cache));
	memset(synCache, -1, sizeof(synCache));
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		init();
		cout << solve(N) << endl;
	}
}