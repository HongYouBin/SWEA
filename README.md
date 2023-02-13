# SWEA

### 5215 햄버거 다이어트

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT

https://github.com/HongYouBin/SWEA/blob/master/5215 햄버거 다이어트\_1.cpp
https://github.com/HongYouBin/SWEA/blob/master/5215 햄버거 다이어트\_1.cpp

- 완전탐색 문제이다. 완전탐색을 구현하는 방법이 2가지가 떠올라 둘 다 사용하여 문제를 풀어보았다.
- 1번은 dfs로 풀었다. 매 단계마다(level 변수) 음식을 섭취할지 안 할지 정한 후 섭취를 하면 칼로리와 맛 점수를 올린 후 다음 단게로 넘어간다.
- 2번은 비트맵을 사용하여 구현했다. 첫 번째 for문은 모든 탐색 가능한 경우의 수를 돌도록 해준다. 각 자리를 볼 때 0이면 탐색하지 않고 1이면 탐색한다는 뜻이다. 두 번째 for문은 몇 번째 bit를 탐색해야 하는지 자리 수를 알려준다. 따라서 shift 연산자로 자리 수만큼 이동한 후 첫번 째 for문의 bit와 비교해준다.
- dfs가 문제에 많이 나오기 때문에 확실히 알아두도록 하자.

### 1952 수영장

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq

https://github.com/HongYouBin/SWEA/blob/master/1952_1.cpp
https://github.com/HongYouBin/SWEA/blob/master/1952_2.cpp

- 첫 번째는 dp로 풀었다. 문제를 보고 dp 점화식을 세울 수 있었다. dp[i]을 i번째 달까지 사용하는 돈의 최소값이라고 정의하면 dp[i] = min(dp[i-1] + 1일 이용권 \* i-1번째 달의 수, dp[i-1] + 1달 이용권, dp[i-3] + 3달 이용권, dp[i-12] + 1년 이용권) 으로 세울 수 있다. 사실 3달 이용권이나 1년 이용권의 가격이 1일 이용권과 한 달 이용권의 가격보다 낮으면 오답이 발생할 수 있어 따로 case를 분리해야 하나 그렇지 않게 설정하여 정답이 된 것 같다.
- 두 버째는 완전탐색으로 구현했다. 각 달마다 총 4가지의 경우의 수가 있어(1일 이용권, 1달 이용권, 3달 이용권, 1년 이용권) 4^12로 시간이 초과될 수 있다. 하지만 1년 이용권은 달에서만 비교해주면 되기 때문에 각 달마다 3가지 경우의 수로 줄일 수 있고 따라서 3^12로 시간복잡도가 줄어든다.
