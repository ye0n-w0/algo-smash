#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    // 이분탐색을 위한 오름차순 정렬
    sort(times.begin(), times.end());

    long long left = 0;
    long long right = (long long)times[times.size() - 1] * n;

    answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long passed = 0; // mid 시간동안 심사받은 사람의 수

        // 각 심사관이 mid 동안 몇명 처리할 수 잇는지 
        for (int i = 0; i < times.size(); i++) {
            passed += (mid / times[i]);
            if (passed >= n) break;
        }

        // 시간이 남는 경우
        if (passed >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}