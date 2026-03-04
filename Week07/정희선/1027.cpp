#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    int max_num_visible = 0;

    for (int i = 0; i < N; i++) {
        int num_visible = 0;

        // 오른쪽
        double max_slope = -1e10;
        for (int j = i + 1; j < N; j++) {
            double slope = (double)(height[j] - height[i]) / (j - i);

            if (slope > max_slope) {
                max_slope = slope;
                num_visible++;
            }
        }

        // 왼쪽
        double min_slope = 1e10;
        for (int j = i - 1; j >= 0; j--) {
            double slope = (double)(height[j] - height[i]) / (j - i);

            if (slope < min_slope) {
                min_slope = slope;
                num_visible++;
            }
        }

        max_num_visible = max(max_num_visible, num_visible);
    }

    cout << max_num_visible << "\n";

    return 0;
}