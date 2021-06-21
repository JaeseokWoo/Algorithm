#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    for (int i = 0; i < phone_book.size(); ++i)
        s.insert(phone_book[i]);
    bool answer = true;

    for (int i = 0; i < phone_book.size(); ++i) {
        string str = phone_book[i];
        int size = str.size();
        for (int j = 0; j < size - 1; ++j) {
            if (s.count(str.substr(0, j + 1))) {
                answer = false;
                break;
            }
        }
        if (!answer) break;
    }
    return answer;
}