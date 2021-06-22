#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < scoville.size(); ++i)
        pq.push(-scoville[i]);

    while (pq.size() > 1 && -pq.top() < K) {
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();
        pq.push(-(first + (second * 2)));
        answer++;
    }

    if (-pq.top() < K) return -1;
    else return answer;
}