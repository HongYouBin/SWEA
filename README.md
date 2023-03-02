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

### 1952 수영장

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo

https://github.com/HongYouBin/SWEA/blob/master/5656.cpp

- 구현으로 풀었다.
- 시간이 오래 걸렸는데 2가지 문제점이 있었다. 첫 번째는 vector의 size() 자료형 때문이었다. int와 vector.size() 반환값의 자료형이 다르다. vector.size()는 sizeOf를 반환한다. 따라서 형 변환을 해줘야 문제가 발생하지 않는다. for문이나 조건문 안에서 해당 실수를 하지 않도록 주의해야 한다.

```
    int tmp = (H - 1 - tmpArr.size());
    // 형 변환을 해줘야 한다.
		for (int r = H - 1; H - 1 - (int)tmpArr.size() < r; --r) {
			grid[r][c] = tmpArr[idx++];
		}
```

- visual studio에서 할당한 메모리를 초과하지 않으면 문제없이 돌아가는 코드가 SWEA에서는 segfault 오류가 발생한다. H값보다 메모리를 크게 잡았음에도 문제가 발생한다.

```
    int T, N, H, W, grid[20][20], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, ans;

    void check(int col) {
	    int row = 0;
	    while (row < H && grid[row][col] == 0) row++;
	    if (row >= H) return;
        .....
```

- 구현을 할 때 문제가 오래 걸렸다. 설계를 꼼꼼하게 한 후 따져야 하는 조건이 설계안에 들어갔는지 확인하는 과정을 거친 후 코딩을 하자.
- 디버깅이 쉽도록 콘솔에 출력하는 방법을 사용하는 것이 좋아보인다.

### 1767 프로세서 연결하기

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf

https://github.com/HongYouBin/SWEA/blob/master/1767.cpp
https://github.com/HongYouBin/SWEA/blob/master/1767.cpp

- 처음에 완전탐색으로 생각하고 각 방향을 설정한 후{O(4^12)} 재귀가 core의 수만큼 도달하면 core를 연결하는 방법으로 구현했다. 시간 초과가 발생했는데 완전탐색이 아닌 백 트랙킹으로 문제를 풀었어야 했다.
- 각 단계마다 core를 연결한 후 연결한 값과 앞으로 최대로 연결 가능한 값이 정답보다 작으면 더이상 탐색하지 않고 return 해야 한다.
- 처음 문제를 설계할 때 완전탐색이라고 바로 단정짓지 말고 최대한 시간을 절약할 수 있는 방법이 무엇이 있는지 고민해봐야 한다.
- SWEA를 풀면서 비슷한 문제를 많이 봤다. 재귀를 진행하면서 현재 재귀 단계에서의 값과 앞으로 재귀를 진행하면서 만들 수 있는 값이 설정한 임시 정답값을 갱신하는 조건이 안나오면 진행을 멈추는 아이디어를 잊지 말고 기억해야 한다.
