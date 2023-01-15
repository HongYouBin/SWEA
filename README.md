# SWEA

### 1285 동전 뒤집기

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT

https://github.com/HongYouBin/SWEA/blob/master/5215 햄버거 다이어트_1.cpp
https://github.com/HongYouBin/SWEA/blob/master/5215 햄버거 다이어트_1.cpp

- 완전탐색 문제이다. 완전탐색을 구현하는 방법이 2가지가 떠올라 둘 다 사용하여 문제를 풀어보았다.
- 1번은 dfs로 풀었다. 매 단계마다(level 변수) 음식을 섭취할지 안 할지 정한 후 섭취를 하면 칼로리와 맛 점수를 올린 후 다음 단게로 넘어간다. 
- 2번은 비트맵을 사용하여 구현했다. 첫 번째 for문은 모든 탐색 가능한 경우의 수를 돌도록 해준다. 각 자리를 볼 때 0이면 탐색하지 않고 1이면 탐색한다는 뜻이다. 두 번째 for문은 몇 번째 bit를 탐색해야 하는지 자리 수를 알려준다. 따라서 shift 연산자로 자리 수만큼 이동한 후 첫번 째 for문의 bit와 비교해준다.
- dfs가 문제에 많이 나오기 때문에 확실히 알아두도록 하자. 
