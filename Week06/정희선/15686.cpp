#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int min_city_chicken_dist = 2e9;
vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;
bool picked[13];

int get_dist(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void calculate(){ // 도시 치킨 거리 합 계산
    int city_chicken_dist = 0;

    for(int i=0; i<houses.size(); i++){
        int min_dist = 50*50;
        for(int j=0; j<chickens.size(); j++){
            if(picked[j]){ // 살리기로 선택한 치킨집 거리만 계산
                min_dist = min(min_dist, get_dist(houses[i], chickens[j]));
            }
        }
        city_chicken_dist += min_dist;
    }
    min_city_chicken_dist = min(min_city_chicken_dist, city_chicken_dist);
}

void solve(int index, int count) { // 백트래킹 로직 (탐색)
    if (count == M){ // 종료 조건 - M개 치킨집 모두 선택
        calculate();
        return;
    }

    if (index == chickens.size()){ // 종료 조건 - 모든 치킨집 탐색 완료
        return;
    }

    // 선택지 1: 현재 치킨집을 살린다
    picked[index] = true;
    solve(index+1, count+1);

    // 선택지 2: 현재 치킨집을 살리지 않는다
    picked[index] = false;
    solve(index+1, count);
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++) { // 지도 입력받으면서 좌표 저장
        for (int j = 0; j < N; j++) {
            int bulding;
            cin >> bulding;
            if (bulding == 1) houses.push_back({i, j});
            else if (bulding == 2) chickens.push_back({i, j});
        }
    }

    solve(0,0);

    cout << min_city_chicken_dist << endl;

    return 0;
}