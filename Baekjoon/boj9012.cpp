#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solve(const string& s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
		st.push(s[i]);
	int right = 0;
	while (!st.empty()) {
		char c = st.top();
		st.pop();
		if (c == ')') right++;
		else right--;
		if (right < 0)
			break;
	}
	return (right == 0);
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		string s;
		cin >> s;
		bool ret = solve(s);
		if (ret == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}