/**
* @date: 2021-07-12
* @version: vol1
* @access: 재귀적으로 매번 현재 위치부터 삼각형 바닥 끝까지 가는 경로 중 거쳐간 숫자의 합이 가장 큰 수를 반환하여 해결하였다.
    (Algospot에도 똑같은 문제 있음)
* @weaknesses & learned:
    1. 재귀적말고 반복적으로 하는 방법도 있다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 500;
int N;
int tri[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

void init(const vector<vector<int>>& triangle) {
    N = triangle.size();
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < triangle[y].size(); ++x)
            tri[y][x] = triangle[y][x];

    memset(cache, -1, sizeof(cache));
}

// 현재 위치가 (y, x)일 때 삼각형의 바닥까지 가는 경로 중 거쳐간 숫자의 합이 가장 큰 수를 반환
int solve(int y, int x) {
    // 기저 사례: 바닥까지 왔을 경우
    if (y == N - 1)
        return tri[y][x];

    int& ret = cache[y][x];
    if (ret != -1) return ret;

    return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + tri[y][x];
}

int solution(vector<vector<int>> triangle) {
    init(triangle);
    int answer = solve(0, 0);
    return answer;
}