#include <string>
#include <vector>

using namespace std;

bool cross(vector<int>& stones, int k, int mid) {
    int count = 0;  // 연속으로 넘어간 돌의 수 

    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < mid) {
            // 돌의 적인 숫자가 건너는 사람보다 작기 때문에 건너뛰어야 함
            count++;
            if (count >= k) // 그리고 못 밟는 돌이 k개 이상이면 건널 수 없음 
                return false;
        }
        else {
            count = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 1;
    int right = 200000000;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (cross(stones, k, mid)) {
            // 건널 수 있으면 현재 mid를 정답으로 저장 -> 더 가능한지 탐색 
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}