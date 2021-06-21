#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> cloths(n, 1);
    for (int i = 0; i < lost.size(); ++i)
        cloths[lost[i]-1]--;
    for (int i = 0; i < reserve.size(); ++i)
        cloths[reserve[i]-1]++;

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (cloths[i] == 0) {
            if (i > 1 && cloths[i - 1] > 1) {
                cloths[i - 1]--;
                cloths[i]++;
            }
            else if (i < n - 1 && cloths[i + 1] > 1) {
                cloths[i + 1]--;
                cloths[i]++;
            }
            else continue;
        }
        answer++;
    }
        
    return answer;
}