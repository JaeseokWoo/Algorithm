/**
* @date: 2021-06-30
* @version: vol1
* @access: 삼항 연산자를 통해 문제를 해결하였다.
*/
#include <iostream>
using namespace std;

char relational(int a, int b) {
	return (a > b ? '>' : (a == b) ? '=' : '<');
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		int a, b;
		cin >> a >> b;
		cout << relational(a, b) << endl;
	}
}