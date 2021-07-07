/**
* @date: 2021-07-27
* @version: vol1
* @access: dijkstra 알고리즘을 이용하여 접근하였다.
* @weaknesses & learned:
	1. 책에서는 노이즈 증폭 값을 log()로 입력받아 기존 dijkstra 알고리즘의 변형없이 하는 방법을 설명한다.(출력할 때 exp() 사용)
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <cstdio>
using namespace std;

const int MAX_N = 10000;
int N, M;
vector<pair<int, double>> adj[MAX_N];

void init() {
	for (int i = 0; i < MAX_N; ++i)
		adj[i].clear();
}

void makeGraph() {
	for (int i = 0; i < M; ++i) {
		int u, v;
		double cost;
		cin >> u >> v >> cost;
		adj[u].push_back(make_pair(v, cost));
		adj[v].push_back(make_pair(u, cost));
	}
}

vector<double> dijkstra(int src) {
	vector<double> dist(N, numeric_limits<double>::max());
	dist[src] = 1;
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(-1, src));

	while (!pq.empty()) {
		int here = pq.top().second;
		double cost = -pq.top().first;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		init();
		cin >> N >> M;
		makeGraph();
		vector<double> ret = dijkstra(0);
		printf("%.10lf\n", ret[N - 1]);
	}
}