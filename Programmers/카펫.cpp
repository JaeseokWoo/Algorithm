#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int yh = 1; yh <= yellow; ++yh) {
        if ((yellow % yh) != 0) continue;
        int yw = yellow / yh;
        if (yw < yh) continue;
        int h = yh + 2;
        int w = yw + 2;
        if (2 * w + 2 * yh == brown) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}
