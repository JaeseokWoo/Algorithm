/**
* @date: 2021-07-01
* @version: vol1
* @access: 트립을 구현하여 매번 k번째 원소를 찾고 삭제하는 방식으로 구현하였다.
* @weaknesses & learned:
	1. (책으로 보고 바로 구현하였지만) 트립(treap)을 구현하는 시간을 많이 소비하였다.
	2. 책에서는 미리 답을 저장할 배열을 할당해 내가 작성한 소스 코드처럼 마지막에 reverse()를 하지 않아도 된다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;

struct Node {
	int key;
	int priority;
	int size;
	Node* left;
	Node* right;
	Node(int _key):key(_key),priority(rand()),size(1),left(NULL),right(NULL){}
	void setLeft(Node* newLeft) {
		left = newLeft;
		calc();
	}
	void setRight(Node* newRight) {
		right = newRight;
		calc();
	}
	void calc() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, int key) {
	if (root == NULL) return NodePair(NULL, NULL);

	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* newNode) {
	if (root == NULL) return newNode;

	if (root->priority < newNode->priority) {
		NodePair splitted = split(root, newNode->key);
		newNode->setLeft(splitted.first);
		newNode->setRight(splitted.second);
		return newNode;
	}

	if (root->key > newNode->key) {
		root->setLeft(insert(root->left, newNode));
	}
	else
		root->setRight(insert(root->right, newNode));
	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, int key) {
	if (root == NULL) return root;

	if (root->key == key) {
		Node*temp =  merge(root->left, root->right);
		delete root;
		return temp;
	}
	if (key < root->key) {
		root->setLeft(erase(root->left, key));
	}
	else
		root->setRight(erase(root->right, key));
	return root;
}

Node* kth(Node* root, int k) {
	if (root == NULL) return root;
	int ls = root->left ? root->left->size : 0;
	if (ls >= k)
		return kth(root->left, k);
	if (ls + 1 == k)
		return root;
	return kth(root->right, k - ls - 1);
}

vector<int> solve(stack<int>& st) {
	Node* root = NULL;
	for (int i = 0; i < N; ++i)
		root = insert(root, new Node(i + 1));
	
	vector<int> ret;
	while (!st.empty()) {
		int k = st.size() - st.top();
		Node* target = kth(root, k);
		ret.push_back(target->key);
		root = erase(root, target->key);
		st.pop();
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N;
		stack<int> st;
		for (int n = 0; n < N; ++n) {
			int num;
			cin >> num;
			st.push(num);
		}
		vector<int> ret = solve(st);
		for (int i = 0; i < ret.size(); ++i)
			cout << ret[i] << ' ';
		cout << endl;
	}
}