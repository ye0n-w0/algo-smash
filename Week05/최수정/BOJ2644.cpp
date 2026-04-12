#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

int n;
int target1, target2;
int m;

vector<int> graph[101];
bool visited[101];

struct Person {
    int id;
    int depth;
};

queue<Person> q;

int bfs(int start, int total) {
    q.push({ start, total });
    visited[start] = true;

    while (!q.empty()) {
        Person x = q.front();
        q.pop();

        // 큐에서 꺼낸 사람이 target2라면 현재 depth 반환
        if (x.id == target2) {
            return x.depth;
        }

        for (int i = 0; i < graph[x.id].size(); i++) {
            int y = graph[x.id][i];

            if (!visited[y]) {
                // x.depth를 큐에 넣을 때 +1 해서 전달
                q.push({ y, x.depth + 1 });
                visited[y] = true;
            }
        }
    }

    // 큐를 다 비워도 target2를 못 찾았으면 관계가 X -> -1 리턴
    return -1;
}

int main() {
    cin >> n;
    cin >> target1 >> target2;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int p, c;
        cin >> p >> c;

        // 양방향 연결
        graph[p].push_back(c);
        graph[c].push_back(p);
    }

    // target1부터 BFS 시작
    int ans = bfs(target1, 0);

    cout << ans << "\n";

    return 0;
}