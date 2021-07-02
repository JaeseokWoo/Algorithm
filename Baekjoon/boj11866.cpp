/**
* @date: 2021-07-02
* @version: vol1
* @access: queue를 통해 매번 요세푸스 순열의 다음 원소를 구한다. K가 N보다 클 경우를 대비해 %를 사용했다. 
* @weaknesses & learned:
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, K;

vector<int> josephus(int N, int K) {
	queue<int> people;
	for (int n = 0; n < N; ++n)
		people.push(n + 1);

	vector<int> ret;
	while (!people.empty()) {
		int pass = (K - 1) % people.size();
		for (int i = 0; i < pass; ++i) {
			people.push(people.front());
			people.pop();
		}
		ret.push_back(people.front());
		people.pop();
	}
	return ret;
}

int main() {
	cin >> N >> K;
	vector<int> ret = josephus(N, K);

	for (int i = 0; i < ret.size(); ++i) {
		if (i == 0) printf("<");
		printf("%d", ret[i]);
		if (i != ret.size() - 1) printf(", ");
		else printf(">\n");
	}
}