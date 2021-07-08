/**
* @date: 2021-07-08
* @version: vol1
* @access: dijkstra 알고리즘을 통해 모든 소방서에 대해서 불난 장소의 최단 경로를 구하였다.
* @weaknesses & learned:
	1. 내가 작성한 소스코드는 모든 소방서에 대해서 dist 값을 0으로 시작해서 풀었는데
	책에서는 가상의 시작점을 만들어 소방서와의 거리를 0으로 설정하여 dijkstra 알고리즘으로 해결하는 방법을 설명한다.
	(동작 과정은 똑같음, 초기에 그래프를 좀 더 구성한 차이)
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAX_V = 1000 + 1;
const int INF = 987654321;
int V, E;	// 장소의 수, 도로의 수
int n, m;	// 화재 장소의 수, 소방서의 수
vector<pair<int, int>> adj[MAX_V];	// pair<장소 번호, 걸리는 시간>

void init() {
	for (int i = 0; i < MAX_V; ++i)
		adj[i].clear();
}

vector<int> dijkstra(const vector<int>& fs) {
	vector<int> dist(V + 1, INF);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < fs.size(); ++i) {
		dist[fs[i]] = 0;
		pq.push(make_pair(0, fs[i]));
	}

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
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
		cin >> V >> E >> n >> m;
		vector<pair<pair<int, int>, int>> edges;
		for (int e = 0; e < E; ++e) {
			int u, v, t;
			cin >> u >> v >> t;
			adj[u].push_back(make_pair(v, t));
			adj[v].push_back(make_pair(u, t));
		}
		vector<int> fired(n); // 화재가 발생한 장소 번호
		vector<int> fs(m);	// 소방서의 위치 번호
		for (int i = 0; i < n; ++i)
			cin >> fired[i];
		for (int i = 0; i < m; ++i)
			cin >> fs[i];

		vector<int> dist = dijkstra(fs);
		int ret = 0;
		for (int i = 0; i < n; ++i)
			ret += dist[fired[i]];
		cout << ret << endl;
	}
}