/**
* @date: 2021-06-29
* @version: vol1
* @access: 여는 괄호와 닫는 괄호를 미리 저장해서 경우에 따라 확인한다.
* @weaknesses & learned:
	1. 책에서는 여는 괄호도 find()함수로 확인한다.
	2. 책에서는 문제를 해결하는 함수에서 bool값을 return하여 추가적인 bool ok 변수를 할당하지 않고 잘못된 경우인 경우 바로 return false 한다.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

const string leftBrackets = "({[";
const string rightBrackets = ")}]";

void brackets2(const string& formula) {
	stack<char> st;

	bool ok = true;
	for (int i = 0; i < formula.size(); ++i) {
		char bracket = formula[i];

		// 왼쪽 괄호면 push
		if (bracket == '(' || bracket == '{' || bracket == '[') {
			st.push(bracket);
			continue;
		}

		// 오른쪽 괄호면 check
		if (st.empty()) {
			ok = false;
			break;
		}
		int index = rightBrackets.find(bracket);
		if (st.top() != leftBrackets[index]) {
			ok = false;
			break;
		}
		st.pop();
	}

	if (ok && st.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		string formula;
		cin >> formula;
		brackets2(formula);
	}
}