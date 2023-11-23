## 문제 출처

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/178870" rel="nofollow">연속된 부분 수열의 합</a>

## 🔍 풀이

간단한 투포인터 문제이다.

sequence의 길이가 최대 100만이기 때문에 O(N^2) 풀이는 불가능하고, O(N) 또는 O(NlogN) 풀이가 필요하다.

그래서, O(N) 풀이가 가능한 투포인터로 접근했다.

합이 K인 경우를 여러 개 찾는 유형의 문제는 대부분 투 포인터 방식으로 접근하는 것 같다.

## ✏️ 추가 지식

투포인터를 위한 while문 조건에 end < sequence.size() 조건을 넣어주었는데, end = -1, sequence.size() = 5인 상황에서 false를 반환했다.

-1 < 5 는 당연하게 true인데 false여서 굉장히 당황했다.

분석해보니 vector의 size() 함수의 반환 타입은 unsigned int 타입이었다. 그리고 end는 그냥 int 타입이다.

end가 0 이상의 정수였다면 아무 문제 없었을텐데 -1이어서 문제가 생기는 것이었다.

int와 unsigned int를 비교하는 과정에서, 기존의 int가 unsigned int로 형변환되고 int 타입의 -1은 unsigned int 타입의 4294967295(= 2^32 - 1)라는 값으로 변환된다.

그래서 당연하게도 false가 반환되는 것이었다.

나는 while문 이전에 int seqlen = sequence.size() 를 통해 int 값으로 길이를 받아두고 while문 조건 안에는 end < seqlen 조건을 작성해주었다.

## 😊 후기

추가지식에 언급한 이슈를 마주하여 어려움을 겪었던 것 말고는 어렵지 않은 문제였다.