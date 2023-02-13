//1952
// 수영장

#include <iostream>
#include <vector>

#define ll long long
#define inf 1e9
using namespace std;

int T, month[13], fee[4], dp[13];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < 4; ++i) cin >> fee[i];
		for (int i = 1; i <= 12; ++i) {
			cin >> month[i];
			dp[i] = inf;
		}

		for (int i = 1; i <= 12; ++i) {
			dp[i] = min(dp[i - 1] + fee[0] * month[i], dp[i - 1] + fee[1]);
			if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + fee[2]);
			if (i >= 12) dp[i] = min(dp[i], dp[i - 12] + fee[3]);
		}
		cout << "#" << tc << " " << dp[12] << '\n';
	}
}