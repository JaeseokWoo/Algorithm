#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < clothes.size(); ++i) {
        if (m.count(clothes[i][1]) == 0)
            m[clothes[i][1]] = 1;
        else m[clothes[i][1]]++;
    }
    map<string, int>::iterator it = m.begin();
    answer = 1;
    while (it != m.end()) {
        answer *= (1 + (*it).second);
        it++;
    }
    return answer - 1;
}