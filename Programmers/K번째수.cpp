#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int c = 0; c < commands.size(); ++c) {
        int i = commands[c][0];
        int j = commands[c][1];
        int k = commands[c][2];
        vector<int> partition;
        for (int begin = i - 1; begin <= j - 1; ++begin)
            partition.push_back(array[begin]);
        sort(partition.begin(), partition.end());
        answer.push_back(partition[k - 1]);
    }

    return answer;
}