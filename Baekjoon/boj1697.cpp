#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
int N, K;

bool isRange(int position) {
	return (position >= 0 && position < MAX);
}

int BFS(int start) {
	vector<int> visited(MAX, -1);
	queue<int> q;
	visited[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		if (isRange(here + 1) && visited[here + 1] == -1) {
			visited[here + 1] = visited[here] + 1;
			if (here + 1 == K) break;
			q.push(here + 1);
		}

		if (isRange(here - 1) && visited[here - 1] == -1) {
			visited[here - 1] = visited[here] + 1;
			if (here - 1 == K) break;
			q.push(here - 1);
		}

		if (isRange(here * 2) && visited[here * 2] == -1) {
			visited[here * 2] = visited[here] + 1;
			if (here * 2 == K) break;
			q.push(here * 2);
		}
	}
	return visited[K];
}

int main(void) {
	cin >> N >> K;
	cout << BFS(N) << endl;
}