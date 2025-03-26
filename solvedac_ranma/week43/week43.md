# solved\.ac 랜덤 마라톤 43주차

<img src="./img/week43unsolved.PNG">

A번 풀기 전에 캡쳐하지 못했다.  

---

## A

### #2605 : 줄 세우기
https://www.acmicpc.net/problem/2605

#### 해결 상태
✅

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-0.svg' width='30'>

#### 사용 알고리즘

**#구현**  
**#자료구조**  

#### 풀이

규칙에 따라 대기줄을 재배열한 결과를 출력하는 문제.  

1. 대기줄에 속한 사람의 수 `n`을 입력받는다.
2. `n` 크개의 배열 `rows`를 선언하고, 각각의 원소에 1 ~ `n` 값을 순서대로 저장한다.
3. 각 사람이 뽑은 카드 번호를 `n`번 반복하여 입력받으며 아래 과정을 수행한다.
    - 3-1. 임시 변수 `temp`를 선언하고 이번에 카드를 뽑은 사람 번호(`rows[i]`)를 저장한다.
    - 3-2. `i` 위치를 기준으로 앞 `num`개의 `rows` 배열 원소값을 바로 뒤 쪽 인덱스에 저장하고, `i` 위치를 기준으로 `num`만큼 앞의 원소 위치에 `temp` 변수 값(원래 `num[i]`에 해당하는 사람 번호)를 저장한다.
4. 최종적으로 재배열된 `rows` 배열의 전체 값을 순서대로 출력한다.

#### 코멘트

A번 브론즈 문제 치고는 좀 생각할거리가 많은 문제이다.  
사실 단순 구현에 가까운 문제인데, 언어 별로 제공되는 배열 자료구조 및 함수를 사용하는 방법도 있고 연결리스트를 사용하는 방법도 있고 굉장히 다양한 방식의 풀이가 가능한 것 같다.  
$N$의 범위가 최대 100이기 때문에 어떤 방식을 쓰든 상관없긴 하다.  

처음에 연결리스트를 써야되나 싶었는데 범위 제한을 보고 귀찮아서 O(N^{2}) 방식으로 대충 구현해버렸다.  
삽입 정렬과 유사하게 임시 변수에 카드를 뽑은 사람 번호를 넣은 뒤 카드 번호만큼 앞 사람들을 뒤로 한 칸씩 밀어버리는 방식이다.  
역시 조건만 충족한다면 빠르고 간단하게 짜는게 최고다.

---

## B

### #29940 : Sum
https://www.acmicpc.net/problem/29940

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-0.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트

---

## C

### #4993 : Red and Black
https://www.acmicpc.net/problem/4993

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-0.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트 

---

## D

### #3793 : Common Subsequence
https://www.acmicpc.net/problem/3793

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-0.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트

---

## E

### #2631 : 줄세우기
https://www.acmicpc.net/problem/2631

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-0.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트

---

## F

### #14570 : 나무 위의 구슬
https://www.acmicpc.net/problem/14570

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-1.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트

---

## G

### #4080 : Two Ends
https://www.acmicpc.net/problem/4080

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-1.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트
  

---

## H

### #1663 : Two Ends
https://www.acmicpc.net/problem/1663

#### 해결 상태
❌

#### 난이도
<img src='https://static.solved.ac/tier_small/relative-1.svg' width='30'>

#### 사용 알고리즘


#### 풀이


#### 코멘트

---

## 결과 및 후기

| A | B | C | D | E | F | G | H |
|---|---|---|---|---|---|---|---|
| ✅ | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ |


