/**
* @date: 2021-06-30
* @version: vol1
* @access: queue를 활용해 후보 구간의 포함된 값을 저장하면서 해결하였다.
* @weaknesses & learned:
*	1. 책에서 난수 신호를 생성할 때 unsigned 자료형을 사용하여 2^32로 나눈 나머지를 취하는 연산을 하지 않았다. 
*	2. 책에서 난수 신호를 생성하는 struct가 좀 더 깔끔하다.
*/
#include <iostream>
#include <queue>
using namespace std;

const long long MOD = (long long)1 << 32;

struct Signal {
	long long prev = 1983;
	int count = 0;
	long long getNext() {
		if (count == 0) {
			++count;
			return prev + 1;
		}
		long long next = (prev * 214013 + 2531011) % MOD;
		prev = next;
		return (next % 10000) + 1;
	}
};

int N, K;
int ITES() {
	queue<int> q;
	int sum = 0;
	int ret = 0;
	Signal signal;
	for (int i = 0; i < N; ++i) {
		int next = int(signal.getNext());
		q.push(next);
		sum += next;
		while (sum >= K) {
			if (sum == K)
				ret++;
			int f = q.front();
			q.pop();

			sum -= f;
		}
	}
	return ret;
}

int main() {
	Signal signal;
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> K >> N;
		cout << ITES() << endl;
	}
}