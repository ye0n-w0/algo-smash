#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 크기가 학생 수이고 원소가 모두 0인 벡터 만들기 
    vector<int> student(n + 2, 0);

    // 1부터 시작하는 인덱스 에러 방지 
    student[0] = 0;
    student[n + 1] = 0;

    // lost에 해당되는 학생은 -1, reserve이면 +1 
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i]]++;
    }

    // 학생 벡터 순회하면서 lost인 학생에서 reserve인 학생이 가능하면 체육복 빌려주기 
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1) {
                student[i]++;
                student[i - 1]--;
            }
            else if (student[i + 1] == 1) {
                student[i]++;
                student[i + 1]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (student[i] >= 0) answer++;
    }

    return answer;
}