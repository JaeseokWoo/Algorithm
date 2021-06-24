#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> waiting;
    queue<int> crossing;
    for (int i = 0; i < truck_weights.size(); ++i)
        waiting.push(truck_weights[i]);
    for (int i = 0; i < bridge_length; ++i)
        crossing.push(0);

    int answer = 0;
    int crossingWeight = 0;
    while (!waiting.empty() || !crossing.empty()) {
        if (!crossing.empty()) {
            int w = crossing.front();
            crossingWeight -= w;
            crossing.pop();
        }
        if (!waiting.empty()) {
            int w = waiting.front();
            if (crossingWeight + w > weight)
                crossing.push(0);
            else if (crossing.size() < bridge_length) {
                crossing.push(w);
                crossingWeight += w;
                waiting.pop();
            }
        }
        answer++;
    }
    return answer;
}