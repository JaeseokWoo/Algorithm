#include <iostream>
#include <stack>
using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> s;
	for (int k = 0; k < K; ++k) {
		int num;
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	int ret = 0;
	while (!s.empty()) {
		ret += s.top();
		s.pop();
	}
	cout << ret << endl;
}