
#include <string>
#include <vector>

using namespace std;

vector<long long> dp(2001, -1);

long long solution(int n) {


    if (n == 1) return 1;
    if (n == 2) return 2;

    // 이미 계산한 적 있으면 바로 리턴 
    if (dp[n] != -1) {
        return dp[n];
    }

    // top-down 방식으로 재귀 
    dp[n] = solution(n - 1) + solution(n - 2);

    return dp[n] % 1234567;

}