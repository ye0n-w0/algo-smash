
# Algo-smash Week 02 스터디

## 📅 이번 주 푼 문제

| 날짜     | 플랫폼 | 문제                                                                                   | 비고           |
| ------ | --- | ------------------------------------------------------------------------------------ | ------------ |
| 260113 | PGS | [68644 두 개 뽑아서 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/68644) | vector / set |
| 260113 | PGS | [42840 모의고사](https://school.programmers.co.kr/learn/courses/30/lessons/42840)        | vector       |
| 260116 | PGS | [42889 실패율](https://school.programmers.co.kr/learn/courses/30/lessons/42889)         | 구현 / 정렬      |
| 260116 | BOJ | [9012 괄호](https://www.acmicpc.net/problem/9012)                                      | stack        |
| 260117 | PGS | [76502 괄호 회전하기](https://school.programmers.co.kr/learn/courses/30/lessons/76502)     | stack        |
| 260117 | BOJ | [1158 요세푸스 문제](https://www.acmicpc.net/problem/1158)                                 | queue        |
| 260117 | PGS | [42586 기능 개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586)       | queue        |

---

##  문제별 핵심 포인트 정리

### 🔹 PGS 68644 — 두 개 뽑아서 더하기

👉 [https://school.programmers.co.kr/learn/courses/30/lessons/68644](https://school.programmers.co.kr/learn/courses/30/lessons/68644)

**핵심 자료구조**

* `vector` / `set`

**알고 갈 포인트**

* 중복 제거 + 정렬이 필요할 때 두 가지 선택지

  * `set` 사용 → **삽입 시 자동 정렬 + 중복 제거**
  * `vector` 사용 → **모두 삽입 후 sort + unique**
* 데이터가 많을수록

  * `set`은 삽입마다 정렬 비용 발생
  * `vector`는 한 번에 정렬 → 더 효율적일 수 있음
* `reserve()`로 **필요한 메모리 미리 확보**하면 성능 개선 가능

---

### 🔹 PGS 42840 — 모의고사

👉 [https://school.programmers.co.kr/learn/courses/30/lessons/42840](https://school.programmers.co.kr/learn/courses/30/lessons/42840)

**핵심 자료구조**

* `vector`

**알고 갈 포인트**

* 반복 패턴은 `% 연산`으로 처리
* `max({a, b, c})`

  * `{}` initializer list로 **여러 값 중 최댓값** 추출 가능
* 로직은 단순하지만

  * **조건 분기 깔끔하게 쓰는 연습**에 좋음

---

### 🔹 PGS 42889 — 실패율

👉 [https://wlals916.tistory.com/11](https://wlals916.tistory.com/11)

**핵심 포인트**

* 구현보다 **반례 설계 능력**이 중요한 문제

**반례 찾기 TIP**
1️⃣ **양 끝값을 항상 의심하자**
2️⃣ **정렬 기준 다시 확인하기**
3️⃣ **자료형 & 범위 체크 (int / double)**

👉 “왜 틀렸는지 설명할 수 있으면, 실력이 올라간다”

---

### 🔹 BOJ 9012 — 괄호

👉 [https://www.acmicpc.net/problem/9012](https://www.acmicpc.net/problem/9012)

**핵심 자료구조**

* `stack`

**알고 갈 포인트**

* 전형적인 **괄호 짝 맞추기 문제**
* 핵심 조건

  * 닫는 괄호가 먼저 나오면 바로 실패
  * 마지막에 스택이 비어 있어야 성공

👉 스택 문제의 **기본 템플릿**

---

### 🔹 PGS 76502 — 괄호 회전하기

👉 [https://wlals916.tistory.com/12](https://wlals916.tistory.com/12)

**핵심 자료구조**

* `stack`

**이번 문제에서 배운 점**

* 루프 안에서 `continue / break` 사용 시 주의

  * **업데이트 로직을 건너뛰지 않는지 반드시 확인**
* 특히 `while`문에서 위험함

**개선 아이디어**

* 괄호 매칭을 `unordered_map`으로 관리 가능
* STL 활용 시 가독성 향상

👉 코테에서 **STL을 아는 것 자체가 무기**

---

### 🔹 BOJ 1158 — 요세푸스 문제

👉 [https://wlals916.tistory.com/13](https://wlals916.tistory.com/13)

**핵심 자료구조**

* `queue`

**알고 갈 포인트**
1️⃣ **순환은 FIFO의 재입력**

* `pop → push` = 원형 구조 구현
* `% 연산 없이도 원형 문제 해결 가능

2️⃣ **보류와 확정의 분리**

* K-1명 → 뒤로 보냄
* K번째 → 제거

3️⃣ **인덱스 관리 대신 상태 관리**

* 배열의 인덱스 지옥에서 벗어남
* 나는 `front()`만 본다

---

### 🔹 PGS 42586 — 기능 개발

👉 [https://wlals916.tistory.com/14](https://wlals916.tistory.com/14)

**핵심 자료구조**

* `queue`

**알고 갈 포인트**
1️⃣ 시뮬레이션 vs 수학적 접근

* 완료일을 미리 계산하면 효율 ↑

2️⃣ 큐는 단순 저장소가 아니다

* **기준(front)을 잡고 흐름을 제어하는 도구**

3️⃣ “왜 이 자료구조인가?”를 설명할 수 있어야 한다


---
## 다음주 할일 
- 스택 못 푼 문제 풀기 (프로그래머스 :크레인 인형 뽑기 게임)
- week02 다시 풀 문제 re
- 해시 & 트리 개념 정리
- 해시 문제 : 7문제 풀기

  > 시간 되면 트리 문제도 풀기
