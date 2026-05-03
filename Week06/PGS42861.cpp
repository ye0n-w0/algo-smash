#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> visited(n, false);

    // pair<비용, 목적지> 형태로 저장
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];

        // 양방향 탐색 가능하도록 양쪽에 추가
        graph[start].push_back({ cost, end });
        graph[end].push_back({ cost, start });

    }

    // 우선순위 큐 생성 - 오름차순으로 
    // top에 가장 작은 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0,0 });

    // bfs 방식으로 탐색 
    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_island = pq.top().second;
        pq.pop();

        if (visited[current_island]) continue;

        visited[current_island] = true;
        answer += current_cost;

        // 방금 연결된 섬에서 뻗어나갈 수 있는 새로운 다리들을 큐에 모두 넣기
        for (int i = 0; i < graph[current_island].size(); i++) {
            int next_cost = graph[current_island][i].first;
            int next_island = graph[current_island][i].second;

            // 아직 방문 안 한 섬으로 가는 다리만 큐에 추가
            if (!visited[next_island]) {
                pq.push({ next_cost, next_island });
            }
        }
    }

    return answer;
}