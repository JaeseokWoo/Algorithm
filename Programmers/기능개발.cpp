#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i)
        q.push((100 - progresses[i] + speeds[i] - 1) / speeds[i]);

    while (!q.empty()) {
        int period = q.front();
        q.pop();
        int count = 1;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            if (period >= q.front()) {
                q.pop();
                count++;
            }
            else
                break;
        }
        answer.push_back(count);
    }

    return answer;
}