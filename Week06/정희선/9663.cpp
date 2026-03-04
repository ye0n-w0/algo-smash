#include <iostream>

using namespace std;

int N;
int ans;
int board[15][15];

bool check(int r, int c) { // 퀸 검사
    // 1) 열 체크
    for (int i = 0; i < r; i++) {
        if (board[i][c] == 1) return false;
    }

    // 2) 대각선 체크 (왼쪽 위)
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // 3) 대각선 체크 (오른쪽 아래)
    for (int i = r - 1, j = c + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solve(int index, int count) { // 백트래킹 로직 (탐색)
    if (count == N){ // 종료 조건 - 퀸을 N개 다 놓음
        ans++;
        return;
    }

    if (index >= N*N){ // 종료 조건 - 체스판 끝까지 확인
        return;
    }

    // 인덱스를 2차원 좌표로 변환
    int r = index / N;
    int c = index % N;

    // 선택지 1: 이 칸에 퀸을 놓는다
    if (check(r,c)){
        board[r][c] = 1;
        // 다음으로 올 수 있는 퀸의 위치 체크
        solve((r+1)*N, count+1); // [조건 1] 같은 행이 아님
        board[r][c] = 0;
    }

    // 선택지 2: 이 칸에 퀸을 놓지 않는다
    if (c+1 < N){ // 행 정보를 solve에서 관리하고 있기 때문에
        solve(index + 1, count);
    }
}

int main(){
    cin >> N;

    solve(0,0);

    cout << ans << endl;

    return 0;
}