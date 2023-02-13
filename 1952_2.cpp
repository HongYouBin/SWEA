#include <iostream>
#include <vector>

#define ll long long
#define inf 1e9
using namespace std;

int T, month[13], fee[4], dp[13], ans;

void solv(int m, int sum) {
	if (m > 12) {
		ans = min(ans, sum);
		ans = min(ans, fee[3]);
		return;
	}

	solv(m + 1, sum + month[m] * fee[0]);
	solv(m + 1, sum + fee[1]);
	solv(m + 3, sum + fee[2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		ans = inf;
		for (int i = 0; i < 4; ++i) cin >> fee[i];
		for (int i = 1; i <= 12; ++i) {
			cin >> month[i];
		}

		solv(1, 0);
		cout << "#" << tc << " " << ans << '\n';
	}
}