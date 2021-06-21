#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const vector<vector<int>> switchs = {
	{0,1,2},
	{3,7,9,11},
	{4,10,14,15},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15},
	{3,14,15},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};
const int INF = 987654321;

void push(vector<int>& clocks, int sw) {
	for (int i = 0; i < switchs[sw].size(); ++i) {
		int s = switchs[sw][i];
		clocks[s] += 3;
		clocks[s] %= 12;
	}
}

int solve(vector<int>& clocks, int sw) {
	// ±âÀú »ç·Ê
	if (sw > 9) {
		for (int i = 0; i < clocks.size(); ++i)
			if (clocks[i] != 0)
				return INF;
		return 0;
	}

	int ret = INF;
	for (int i = 0; i < 4; ++i) {
		push(clocks, sw);
		ret = min(ret, ((i + 1) % 4) + solve(clocks, sw + 1));
	}

	return ret;
}

int main() {
	int cases;
	cin >> cases;

	for (int cc = 0; cc < cases; ++cc) {
		vector<int> clocks(16);
		for (int i = 0; i < 16; ++i) {
			cin >> clocks[i];
			clocks[i] %= 12;
		}

		int ret = solve(clocks, 0);
		if (ret == INF) cout << -1 << endl;
		else cout << ret << endl;
	}
}