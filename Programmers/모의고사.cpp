#include <string>
#include <vector>
#include <queue>

using namespace std;
const vector<vector<int>> patterns = {
    {1,2,3,4,5},
    {2,1,2,3,2,4,2,5},
    {3,3,1,1,2,2,4,4,5,5}
};

vector<int> solution(vector<int> answers) {
    vector<int> point(3, 0);
    vector<queue<int>> pattern(3);
    vector<int> answer;

    int max = 0;
    for (int i = 0; i < answers.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (pattern[j].empty())
                for (int k = 0; k < patterns[j].size(); ++k)
                    pattern[j].push(patterns[j][k]);
            int num = pattern[j].front();
            pattern[j].pop();
            if (num == answers[i]) {
                point[j]++;
                if (max < point[j])
                    max = point[j];
            }  
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (point[i] == max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
   vector<int> answer= solution({ 1,3,2,4,2 });
   for (int i = 0; i < answer.size(); ++i)
       cout << answer[i] << " ";
}