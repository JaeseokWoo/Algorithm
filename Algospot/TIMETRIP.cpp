/**
* @date: 2021-07-08
* @version: vol1
* @access: bellmanFord 알고리즘을 통해 가장 빠른 시간과 가장 늦은 시간을 구했다.
* @weaknesses & learned:
	1. 책에서는 UNREACHABLE을 인지 확인하는 reachable[][]를 플로이드의 최단 거리 알고리즘을 통해 확인하였고,
	내가 작성한 코드에서는 적당히 큰 값 100000000을 두었다.
	why) 적당히 큰 값 100000000? => 음수 가중치가 있기 때문에 완화가 반복될수록 처음 설정한 INF보다 작아질 수 있기 때문에
	2. 책 풀이에서 언급한 함정인 음수 사이클이 있어도 0번 정점에서 1번 정점으로 가는 경로에 음수 사이클이 없을 경우를 생각하지 못했다.
	(근데 내가 작성한 코드는 그냥 음수 사이클이 있으면 INFINITY로 간주하였는데 왜 통과했지?)
	3. 책에서는 함정을 reachable[][]을 통해 음수 사이클에서 1번 정점으로 가는 경로가 있는지 판단하여 INFINITY 인지 아닌지 확인한다.
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V, W;
vector<pair<int, int>> adj[MAX_V];	// (정점의 번호, 간선의 가중치) 쌍

void init() {
	for (int i = 0; i < MAX_V; ++i)
		adj[i].clear();
}

vector<int> bellmanFord(int src) {
	vector<int> upper(V, INF);
	upper[src] = 0;

	bool updated = false;
	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}

void reverse() {
	for (int here = 0; here < V; ++here) {
		for (int i = 0; i < adj[here].size(); ++i) {
			adj[here][i].second = -adj[here][i].second;
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> V >> W;
		init();
		for (int w = 0; w < W; ++w) {
			int u, v, cost;
			cin >> u >> v >> cost;
			adj[u].push_back(make_pair(v, cost));
		}
		vector<int> ret1 = bellmanFord(0);
		if (ret1[1] > 100000000) {
			cout << "UNREACHABLE" << endl;
			continue;
		}
		reverse();
		vector<int> ret2 = bellmanFord(0);

		if (ret1.empty()) {
			cout << "INFINITY";
		}
		else
			cout << ret1[1];
		cout << ' ';

		if (ret2.empty()) {
			cout << "INFINITY" << endl;;
		}
		else
			cout << -ret2[1]<<endl;
	}
}