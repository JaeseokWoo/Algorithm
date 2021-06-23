#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int c, int target, int step) {
    // 기저 사례: step이 마지막 단계 + c==target인 경우
    if (step == numbers.size() && c == target) return 1;
    // 기저 사례: step이 numbers.size()를 넘은 경우
    if (step >= numbers.size()) return 0;

    int ret = 0;
    ret += dfs(numbers, c - numbers[step], target, step + 1);
    ret += dfs(numbers, c + numbers[step], target, step + 1);

    return ret;
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = dfs(numbers, 0, target, 0);
    return answer;
}
