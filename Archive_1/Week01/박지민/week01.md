
# [Week 01] C++ STL (I/O, Vector, Set, Map)
**발표자: 박지민**

---

## 1. 입출력 최적화 (I/O Optimization)
> "무심코 쓴 `cin/cout`이 시간 초과의 원인이 될 수 있습니다."

- **핵심 코드**
  ```cpp
  ios::sync_with_stdio(false); // C와 C++의 입출력 동기화 해제
  cin.tie(nullptr);            // 입력 전 출력 버퍼 flush 방지
  ```
- **왜 쓰는가?**: C++ 스트림이 C의 `stdio`와 동기화를 유지하느라 발생하는 오버헤드를 제거하여 속도를 비약적으로 높입니다.
- **주의사항**: 
    - 이 설정을 쓰면 `printf`, `scanf`를 혼용할 때 출력 순서가 꼬이는 **Undefined Behavior**가 발생할 수 있습니다.
    - 디버깅용으로 섞어 쓰지 않도록 주의해야 합니다.

🔗 [자세한 정리: 입출력 최적화 개념](https://wlals916.tistory.com/5)

---

## 2. Vector: 동적 배열의 정체와 성능
> "연속된 메모리가 주는 장점과 재할당의 대가"

- **연속성(Continuity)**: 데이터가 메모리에 나란히 붙어 있어 캐시 효율이 높고 `O(1)` 접근이 가능합니다.
- **Size vs Capacity**:
    - `size`: 실제 원소 개수 / `capacity`: 할당된 공간.
    - **재할당(Reallocation)**: 공간이 다 차면 보통 2배 큰 메모리로 이사를 갑니다(복사 비용 발생).
- **실전 팁**:
    - `reserve()`: 데이터를 많이 넣을 예정이라면 미리 메모리를 예약해 재할당 비용을 막아야 합니다.
    - `erase()`: 중간 삭제는 `O(N)`입니다. 반복문 내 `erase` 남발은 시간 초과의 주범입니다.
    - **Remove-Erase Idiom**: `v.erase(remove(...), v.end())` 패턴으로 효율적인 삭제가 가능합니다.

🔗 [자세한 정리: vector의 동적 배열 구조](https://wlals916.tistory.com/4)

---

## 3. Set & 정렬된 데이터 관리
> "중복 제거가 목적이라면 항상 Set이 정답일까?"

- **Set vs Vector+Sort+Unique**:
    - **Set**: 삽입할 때마다 `O(log N)`으로 정렬 상태 유지. (포인터 기반 트리 구조)
    - **Vector 패턴**: 입력을 다 받고 한 번에 `sort` + `unique`. (연속 메모리 기반, 실제 코테에서 더 빠를 때가 많음)
- **Comparator 주의점 (Strict Weak Ordering)**:
    - 비교 함수 작성 시 `a < b`가 참이면 `b < a`는 반드시 거짓이어야 합니다. (`a <= b` 사용 금지)
    - 이를 어기면 데이터가 사라지거나 런타임 에러가 발생할 수 있습니다.
- **Set의 lower_bound**:
    - **반드시 멤버 함수** `s.lower_bound()`를 써야 `O(log N)`입니다. (`std::lower_bound()`는 `O(N)`으로 동작)

🔗 [자세한 정리: set 활용과 주의점](https://wlals916.tistory.com/7)

---

## 4. Map: 효율적인 Key-Value 매핑
> "데이터를 조회했을 뿐인데, 새로운 데이터가 생겼다?"

- **Map(Tree) vs Unordered_map(Hash)**:
    - `map`: 안정적인 `O(log N)`, 자동 정렬.
    - `unordered_map`: 평균 `O(1)`, 최악 `O(N)`. (해시 저격 데이터 입력 시 위험할 수 있음)
- **최대 실수 방지: `m[key]`**:
    - `m[key]`에 접근할 때 해당 키가 없으면 **기본값(0 등)으로 데이터가 자동 삽입**됩니다.
    - 단순 조회나 존재 확인은 `find()`나 `count()`를 써야 로직이 꼬이지 않습니다.
- **고급 활용**:
    - 빈도수 세기(`counter[s]++`)에 최적화되어 있습니다.
    - `reserve()`를 활용해 `unordered_map`의 Rehash 비용을 줄일 수 있습니다.
    - 순회 중 원소 삭제 시, `it = m.erase(it)` 패턴을 사용하여 iterator 깨짐을 방지해야 합니다.

🔗 [자세한 정리: map 개념 및 실전 버그 잡기](https://wlals916.tistory.com/8)
