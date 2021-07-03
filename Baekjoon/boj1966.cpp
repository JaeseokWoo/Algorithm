/**
* @date: 2021-07-03
* @version: vol1
* @access: queue를 사용해 매번 우선순위가 높은 문서를 찾아 수행한다.
* @weaknesses & learned:
	1. 우선순위 큐로 문서의 우선 순위를 관리하는 방법도 알았지만 내림차순으로 sort하여 풀었다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

int solve(vector<int>& doc) {
	queue<pair<int, int>> q; // <중요도,idx>

	for (int i = 0; i < doc.size(); ++i)
		q.push(make_pair(doc[i], i));
	sort(doc.begin(), doc.end(), greater<int>());
	
	for (int i = 0; i < doc.size(); ++i) {
		while (q.front().first != doc[i]) {
			q.push(q.front());
			q.pop();
		}
		if (q.front().second == M)
			return i + 1;
		q.pop();
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N >> M;
		vector<int> doc(N);
		for (int i = 0; i < N; ++i)
			cin >> doc[i];
		cout << solve(doc) << endl;
	}
}