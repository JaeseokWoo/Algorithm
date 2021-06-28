/* 
* date: 2021-06-28 
* version: vol1
* brief: K값이 N보다 클 경우를 고려해서 %를 사용하여 다음 자살할 사람을 계산
* plus: 책의 풀이에서는 list와 iterator를 통해 구현되어 있다.(소스 코드가 더 간단하고, 효율적이라고 생각한다.)
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N >> K;
		queue<int> q;
		for (int n = 1; n <= N; ++n)
			q.push(n);
		while (q.size() > 2) {
			q.pop();
			int cycle = (K - 1) % q.size();
			for (int i = 0; i < cycle; ++i) {
				q.push(q.front());
				q.pop();
			}
		}
		vector<int>ret(2);
		ret[0] = q.front();
		q.pop();
		ret[1] = q.front();
		q.pop();
		sort(ret.begin(), ret.end());
		cout << ret[0] << ' ' << ret[1] << endl;
	}
}