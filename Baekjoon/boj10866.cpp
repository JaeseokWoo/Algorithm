/**
* @date: 2021-07-05
* @version: vol1
* @access: Node struct와 Deque struct를 직접 구현하여 접근하였다.
* @weaknesses & learned:
*	1. pop()할 때 먼저 head나 tail을 옮기고 그 값이 NULL인지를 판단하면 좀 더 분기문이 깔끔할 것 같다.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* prov;
	Node* next;
	Node(int _value) :value(_value), prov(NULL), next(NULL) {}
};

struct Deque {
	Node* head;
	Node* tail;
	int length;
	Deque() :length(0), head(NULL), tail(NULL) {}
	
	void push_front(Node* node) {
		if (length == 0)
			head = tail = node;
		else {
			node->next = head;
			head->prov = node;
			head = node;
		}
		length++;
		return;
	}

	void push_back(Node* node) {
		if (length == 0)
			head = tail = node;
		else {
			node->prov = tail;
			tail->next = node;
			tail = node;
		}
		length++;
		return;
	}

	int pop_front() {
		if (length == 0)
			return -1;
		Node* target = head;
		if (head == tail) {
			head = tail = target->next;
		}
		else {
			head = target->next;
			head->prov = NULL;
		}

		int ret = target->value;
		delete target;
		length--;
		return ret;
	}

	int pop_back() {
		if (length == 0)
			return -1;
		Node* target = tail;
		if (head == tail) {
			head = tail = target->prov;
		}
		else {
			tail = target->prov;
			tail->next = NULL;
		}

		int ret = target->value;
		delete target;
		length--;
		return ret;
	}

	int size() {
		return length;
	}

	int empty() {
		if (length == 0) return 1;
		return 0;
	}

	int front() {
		if (length == 0) return -1;
		return head->value;
	}

	int back() {
		if (length == 0) return -1;
		return tail->value;
	}
};

int main() {
	int N;
	cin >> N;
	Deque d;
	for (int n = 0; n < N; ++n) {
		string command;
		cin >> command;
		if (command == "push_back") {
			int value;
			cin >> value;
			d.push_back(new Node(value));
		}
		else if (command == "push_front") {
			int value;
			cin >> value;
			d.push_front(new Node(value));
		}
		else if (command == "pop_front") {
			cout << d.pop_front() << endl;
		}
		else if (command == "pop_back") {
			cout << d.pop_back() << endl;
		}
		else if (command == "size") {
			cout << d.size() << endl;
		}
		else if (command == "empty") {
			cout << d.empty() << endl;
		}
		else if (command == "front") {
			cout << d.front() << endl;
		}
		else if (command == "back") {
			cout << d.back() << endl;
		}
	}
}