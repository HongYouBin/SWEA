#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define pip pair<int, pair<int, int>>
using namespace std;

int T, N, H, W, grid[20][20], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, ans;

void check(int col) {
	int row = 0;
	while (row < H && grid[row][col] == 0) row++;
	if (row >= H) return;

	int cnt = 0;
	vector<vector<bool>> visited(H, vector<bool>(W));
	visited[row][col] = 1;
	queue<pip> que;
	que.push({ grid[row][col], {row, col} });
	grid[row][col] = 0;

	while (!que.empty()){
		int curR = que.front().second.first, curC = que.front().second.second, totalDst = que.front().first; que.pop();
		for (int dir = 0; dir < 4; ++dir) {
			for (int dst = 1; dst <= totalDst - 1; ++dst) {
				int nxR = curR + dx[dir] * dst, nxC = curC + dy[dir] * dst;
				if (nxR < 0 || H <= nxR || nxC < 0 || W <= nxC) continue;
				if (visited[nxR][nxC] || grid[nxR][nxC] == 0) continue;
				que.push({ grid[nxR][nxC], {nxR, nxC} });
				visited[nxR][nxC] = 1;
				grid[nxR][nxC] = 0;
			}
		}
	}

	for (int c = 0; c < W; ++c) {
		vector<int> tmpArr;
		for (int r = H - 1; 0 <= r; --r) {
			if (grid[r][c] == 0) continue;
			tmpArr.emplace_back(grid[r][c]);
			grid[r][c] = 0;
		}
		int idx = 0;
		int tmp = (H - 1 - tmpArr.size());
		for (int r = H - 1; H - 1 - (int)tmpArr.size() < r; --r) {
			grid[r][c] = tmpArr[idx++];
		}
	}
}

void solv(int level) {
	if (level == N) {
		//exit condition
		int cnt = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (grid[i][j] != 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int memo[20][20];
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			memo[i][j] = grid[i][j];
		}
	}

	for (int i = 0; i < W; ++i) {
		check(i);
		solv(level + 1);
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				grid[i][j] = memo[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		ans = 1e9;
		cin >> N >> W >> H;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> grid[i][j];
			}
		}

		solv(0);
		cout << "#" << tc << " " << ans << '\n';
	}
}
/*
2
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
3 6 7
1 1 0 0 0 0
1 1 0 0 1 0
1 1 0 0 4 0
4 1 0 0 1 0
1 5 1 0 1 6
1 2 8 1 1 6
1 1 1 9 2 1
*/