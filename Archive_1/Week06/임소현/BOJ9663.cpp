#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

pair<int, int> queen[15];
int count = 0;

void dfs(int N, int start, int queen_no) {
  if (N == queen_no + 1) { // 퀸을 다 배치한 경우
    cout << count;
    return;
  }
  for (int i = start; i < N; i++) {
    queen[i] = {}
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  // 같은 행, 같은 열, 같은 대각선 X

  int N;

  cin >> N;

  dfs(0, 0);

  return 0;
}
