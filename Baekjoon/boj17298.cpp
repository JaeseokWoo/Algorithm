/*
 * date: 2021-06-28
 * version: vol1
 * Programmers의 코딩테스트 연습 > 스택/큐 > 주식가격 문제와 거의 유사하다.
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
int N;
int seq[MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	stack<int> st;
	vector<int> ret(N, -1);
	for (int i = 0; i < N; ++i) {
		while (!st.empty() && seq[st.top()] < seq[i]) {
			int index = st.top();
			st.pop();
			ret[index] = seq[i];
		}
		st.push(i);
	}
	
	for (int i = 0; i < N; ++i)
		cout << ret[i] << ' ';
}