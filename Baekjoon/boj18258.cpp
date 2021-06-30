/**
* @date: 2021-06-30
* @version: vol1
* @access: Node라는 연결리스트 형식으로 queue를 구현하였다.
* @weaknesses & learned:
*	1. cin, cout 입출력이 너무 느려서 cin.tie(NULL); cin.sync_with_stdio(false); 사용
*	2. 좀 더 깔끔한 queue 구현을 공부해야겠다.
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* next;
};

struct queue {
private:
	Node* begin;
	Node* end;
	int length;
public:
	queue() : length(0), end(0), begin(0) {}
	void push(int v) {
		Node* newNode = new Node();
		newNode->value = v;
		newNode->next = 0;

		if (this->length == 0)
			begin = end = newNode;
		else {
			end->next = newNode;
			end = end->next;
		}
		this->length++;
	}
	int pop() {
		if (this->length == 0) return -1;
		int ret = begin->value;
		Node* target = begin;
		begin = begin->next;

		if (target == end)
			end = 0;

		delete target;
		this->length--;
		return ret;
	}
	int size() {
		return this->length;
	}
	int empty() {
		return (this->length == 0 ? 1 : 0);
	}
	int front() {
		if (this->length == 0) return -1;
		return this->begin->value;
	}
	int back() {
		if (this->length == 0) return -1;
		return this->end->value;
	}
};

int N;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	queue q = queue();
	for (int n = 0; n < N; ++n) {
		string command;
		cin >> command;
		if (command == "push") {
			int value;
			cin >> value;
			q.push(value);
		}
		else if (command == "pop") {
			printf("%d\n", q.pop());
		}
		else if (command == "front") {
			printf("%d\n", q.front());
		}
		else if (command == "back") {
			printf("%d\n", q.back());
		}
		else if (command == "size") {
			printf("%d\n", q.size());
		}
		else if (command == "empty") {
			printf("%d\n", q.empty());
		}
	}
}