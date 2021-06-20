#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> cache;
    for (int i = 0; i < completion.size(); ++i) {
        if (cache.count(completion[i]) == 0)
            cache[completion[i]] = 1;
        else
            cache[completion[i]]++;
    }
    for (int i = 0; i < participant.size(); ++i) {
        if (cache.count(participant[i]) == 0 || cache[participant[i]] == 0)
            answer = participant[i];
        else
            cache[participant[i]]--;
    }

    return answer;
}