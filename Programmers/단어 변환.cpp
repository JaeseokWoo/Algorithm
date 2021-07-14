/**
* @date: 2021-07-14
* @version: vol1
* @access: words에 있는 단어들을 각각 그래프의 정점으로 하고 변환할 수 있을 경우 간선으로 연결시킨 후 bfs 알고리즘을 통해 문제를 해결하였다.
* @weaknesses & learned:
    1. bfs 알고리즘을 구현할 때 q.push()를 작성하지 않아 디버그하는데 시간이 걸렸다.
    2. 따로 adj라는 인접 그래프를 만들지 않고 bfs 알고리즘에서 바로 words에 있는 단어들과 비교하여 하는 방식도 있다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = 50 + 1;
int V;
vector<int> adj[MAX_V];

void makeGraph(string& begin, vector<string>& words) {
    words.push_back(begin);
    V = words.size();

    int wordSize = begin.size();
    for (int u = 0; u < words.size(); ++u) {
        for (int i = 0; i < wordSize; ++i) {
            string target = words[u];
            for (int alphabet = 0; alphabet < 26; ++alphabet) {
                target[i] = alphabet + 'a';
                for (int v = 0; v < words.size(); ++v) {
                    if (target == words[v] && target != words[u])
                        adj[u].push_back(v);
                }
            }
        }
    }

}

int bfs(int start, const string& end, vector<string>& words) {
    vector<int> dist = vector<int>(V, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            if (dist[there] == -1) {
                dist[there] = dist[here] + 1;
                if (words[there] == end)
                    return dist[there];
                q.push(there);
            }
        }
    }
    return 0;
}


int solution(string begin, string target, vector<string> words) {
    makeGraph(begin, words);
    int answer = bfs(V - 1, target, words);
    return answer;
}