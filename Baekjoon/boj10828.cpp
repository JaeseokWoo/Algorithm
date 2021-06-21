#include <iostream>
#include <string>
using namespace std;
struct Node {
	int value;
	Node* child;
};

struct Stack {
private:
	int s;
	Node* root;
public:
	Stack() : s(0), root(0) {}
	void push(int x) {
		Node* t = new Node();
		t->value = x;
		if (this->root == 0) {
			this->root = t;
			root->child = 0;
		}
		else {
			t->child = this->root;
			this->root = t;
		}
		s++;
		return;
	}
	int pop() {
		if (this->empty()) return -1;
		int value = root->value;
		Node* temp = root;
		root = root->child;
		delete temp;
		s--;
		return value;
	}
	int size() {
		return s;
	}
	int empty() {
		if (this->s == 0) return 1;
		else return 0;
	}
	int top() {
		if (this->empty()) return -1;
		return root->value;
	}
};

int main() {
	Stack s = Stack();
	int N;
	cin >> N;
	for (int n = 0; n < N; ++n) {
		string op;
		cin >> op;
		if (op == "push") {
			int value;
			cin >> value;
			s.push(value);
		}
		else if (op == "pop") {
			int value = s.pop();
			cout << value << endl;
		}
		else if (op == "size") {
			int size = s.size();
			cout << size << endl;
		}
		else if (op == "empty") {
			int ret = s.empty();
			cout << ret << endl;
		}
		else if (op == "top") {
			int value = s.top();
			cout << value << endl;
		}
	}
}