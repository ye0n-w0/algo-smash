#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++) {
        land[i][0] += max({ land[i - 1][1], land[i - 1][2], land[i - 1][3] });
        land[i][1] += max({ land[i - 1][0], land[i - 1][2], land[i - 1][3] });
        land[i][2] += max({ land[i - 1][0], land[i - 1][1], land[i - 1][3] });
        land[i][3] += max({ land[i - 1][0], land[i - 1][1], land[i - 1][2] });
    }

    // 마지막행까지
    int last_row = land.size() - 1;
    int answer = max({ land[last_row][0], land[last_row][1], land[last_row][2], land[last_row][3] });

    return answer;
}