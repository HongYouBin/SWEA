#include <iostream>
#include <vector>

#define inf 1e9
using namespace std;

int T, N, L, ans = 0;

vector<int> taste(21), cal(21);

void dfs(int level, int tSum, int cSum) {
	if (cSum > L) return;
	if (level == N) {
		ans = max(ans, tSum);
		return;
	}
	if (cSum <= L) ans = max(ans, tSum);
	
	dfs(level + 1, tSum + taste[level], cSum + cal[level]);
	dfs(level + 1, tSum, cSum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		ans = 0;

		cin >> N >> L;
		for (int i = 0; i < N; ++i) {
			cin >> taste[i] >> cal[i];
		}
		dfs(0, 0, 0);
		cout << "#" << tc << ' ' << ans << '\n';
	}
}
