/**
* @date: 2021-06-30
* @version: vol1
* @access: preorder, inorder이 주어졌을 때 재귀적으로 postorder을 구했다. 
* @weaknesses & learned:
*	1. 책에 풀이에서는 바로 출력하여 내가 작성한 것 처럼 추가적인 postorder을 저장하는 배열이 필요 없었다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
int N;
vector<int> ret;

void traversal(queue<int>& preorder, const vector<int> inorder) {
	// 기저사례
	if (inorder.size() == 0) return;
	if (inorder.size() == 1) {
		preorder.pop();
		ret.push_back(inorder[0]);
		return;
	}
	int root = preorder.front();
	preorder.pop();
	int idx = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	vector<int> left(inorder.begin(), inorder.begin() + idx);
	vector<int> right(inorder.begin() + idx + 1, inorder.end());
	traversal(preorder, left);
	traversal(preorder, right);
	ret.push_back(root);
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		vector<int> inorder(N);
		queue<int> preorder;
		for (int n = 0; n < N; ++n) {
			int num;
			cin >> num;
			preorder.push(num);
		}
		for (int n = 0; n < N; ++n) {
			cin >> inorder[n];
		}
		ret.clear();
		traversal(preorder, inorder);
		for (int i = 0; i < ret.size(); ++i)
			cout << ret[i] << " ";
		cout << endl;
	}
}