/* 
* @date: 2021-06-29
* @version: vol1
* @access: union-find 자료 구조를 사용하여 서로 연결되지 않은 마을 간의 비용이 가장 낮은 다리를 n-1개를 선택하여 계산한다.
* @weaknesses & learned:
1. union-find 자료 구조에서 rank[]배열(트리의 높이)을 두어 merge할 때 최적화할 수 있다.
2. union-find를 struct로 구현했으면 좀 더 깔끔하고 좋았을 것이라 생각한다.
3. vector<pair<int, int>> edges[]를 새로 두지 말고 기존의 vector<vector<int>> costs를 compare()를 구현하여 바로 정렬하는 것이 좋았을 것이라 생각한다.
4. 내가 접근한 방법이 kruskal방식이었고, prim 알고리즘으로 접근하는 방법도 있었다.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_n = 100;
int group[MAX_n];

void init(int n) {
    for (int i = 0; i < n; ++i)
        group[i] = i;
}

int root(int a) {
    if (group[a] != a)
        return group[a] = root(group[a]);
    return a;
}

bool inGroup(int a, int b) {
    a = root(a); b = root(b);
    if (a == b) return true;
    else return false;
}

void merge(int a, int b) {
    a = root(a); b = root(b);
    if (a == b) return;

    group[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    init(n);

    vector<pair<int, int>> edges(costs.size()); //pair<다리의 비용, 인덱스>를 저장
    for (int i = 0; i < costs.size(); ++i)
        edges[i] = make_pair(costs[i][2], i);
    sort(edges.begin(), edges.end()); // 다리의 비용이 오름차순으로 저장

    // 다리를 n-1개 건설하면 된다.
    int count = 0;
    int i = 0;
    while (count < n - 1) {
        int index = edges[i].second;
        int A = costs[index][0];
        int B = costs[index][1];
        if (inGroup(A, B)) {
            ++i;
            continue;
        }
        merge(A, B);
        answer += edges[i].first;
        count++;
        i++;
    }

    return answer;
}