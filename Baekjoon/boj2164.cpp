/**
* @date: 2021-07-01
* @version: vol1
* @access: list로 card번호를 저장하고 문제를 풀었다.
* @weaknesses & learned:
	1. 풀고보니 뒤에만 push하고 앞에서만 pop하므로 queue로 해도 된다는 것을 알게되었다.
*/
#include <iostream>
#include <list>
using namespace std;

int solve(int n) {
	list<int> cards;
	for (int i = 0; i < n; ++i)
		cards.push_back(i + 1);
	while (cards.size() > 1) {
		cards.pop_front();
		int card = cards.front();
		cards.pop_front();
		cards.push_back(card);
	}
	return cards.front();
}

int main() {
	int N;
	cin >> N;
	cout << solve(N) << endl;
}