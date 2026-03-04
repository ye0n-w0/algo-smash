#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // 입/출력 속도 빠르게

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 정렬 - 람다 함수
    sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int num_meetings = 0;
    int end_time = 0;

    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= end_time) {
            num_meetings++;
            end_time = meetings[i].second;
        }
    }

    cout << num_meetings << "\n";

    return 0;
}