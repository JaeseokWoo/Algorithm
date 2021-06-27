/*
 *	date: 2021-06-27
 *	version: vol1
 *	결과를 출력하는 부분에서 endl 사용시 시간초과를 받아 '\n'을 사용 
 */
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;
	
	vector<int> sequence(N);
	for (int i = 0; i < N; ++i)
		cin >> sequence[i];
		
	stack<int> st;
	st.push(0);
	
	int next = 1;
	bool ok = true;
	vector<char> ret;
	for (int n = 0; n < N; ++n) {
		int num = sequence[n];
		while (st.top() < num) {
			st.push(next++);
			ret.push_back('+');
		}
		if (st.top() == num) {
			st.pop();
			ret.push_back('-');
			continue;
		}
		else {
			ok = false;
			break;
		}
	}
	if (ok) {
		for (int i = 0; i < ret.size(); ++i)
			cout << ret[i] << "\n";
	}
	else cout << "NO" << endl;
}