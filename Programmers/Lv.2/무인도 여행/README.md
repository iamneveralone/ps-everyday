## 문제 출처

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/154540" rel="nofollow">무인도 여행</a>

## 🔍 풀이

전형적인 DFS 문제이다.

사실상 이차원 배열 형태의 maps의 각 칸을 순회하면서, 칸의 내용이 X가 아니고 (maps[i][j] != 'X') 방문한 적이 없는 (!visited[i][j]) 칸에 대해서 DFS 함수를 수행한다.

DFS 수행 과정에서 연결된 땅들의 숫자의 합은 전역 변수 area에 저장하고, DFS 수행 후 area = 0으로 초기화해준다.

## ✏️ 추가 지식

없다.

## 😊 후기

5분 이내로 풀었던 굉장히 쉬운 문제이다.