/**
* @date: 2021-07-02
* @version: vol1
* @access: 트립을 사용해 매번 중간값을 찾아 계산하였다.
* @weaknesses & learned:
*	1. 책에서는 트립으로 해결하는 방법과 priority_queue로 minHeap과 maxHeap을 구현하여 접근하였다.
	(힙은 대개 배열로 구현되어 있어, 노드를 접근하기 위해 포인터를 따라가야하는 트립보다 훨씬 빠르다고 한다.)
	2. 난수 생성기 RNG를 구현할 때 연산 과정에서 정수 오버플로우가 나지 않도록 64비트 정수(long long)로 캐스팅하는 것을 생각 못 했다. 
*/
#include <iostream>
using namespace std;

const unsigned int MOD = 20090711;

struct RNG {
	unsigned int seed = 1983;
	unsigned int a, b;
	RNG(int _a, int _b) : a(_a), b(_b){}
	unsigned int next() {
		unsigned int ret = seed;
		seed = (seed * (long long)a + b) % MOD;
		return ret;
	}
};

struct Node {
	int key;
	int priority;
	int size;
	Node* left;
	Node* right;
	Node(const int& _key):key(_key), priority(rand()),size(1),left(NULL), right(NULL){}
	void setLeft(Node* newLeft) {
		left = newLeft;
		calcSize();
	}
	void setRight(Node* newRight) {
		right = newRight;
		calcSize();
	}
	void calcSize() {
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

Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;

	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRight(insert(root->right, node));
	}
	return root;
}

Node* kth(Node* root, int k) {
	if (root == NULL) return root;
	int ls = root->left ? root->left->size : 0;
	if (k <= ls)
		return kth(root->left, k);
	if (ls + 1 == k)
		return root;
	return kth(root->right, k - ls - 1);
}

int N, a, b;

int solve() {
	Node* root = NULL;
	int ret = 0;
	RNG rng = RNG(a, b);
	for (int i = 1; i <= N; ++i) {
		root = insert(root, new Node(rng.next()));
		Node* mid = kth(root, (i + 1) / 2);
		ret += mid->key;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> N >> a >> b;
		cout << solve() << endl;
	}
}