#include <iostream>
#include <vector>

#define inf 1e9
using namespace std;

int T, N, L, ans = 0;

vector<int> taste(21), cal(21);

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
		
		for (int bit = 0; bit < (1 << N); ++bit) {
			int tSum = 0, cSum = 0;
			for (int t = 0; t < N; ++t) {
				int check = (1 << t);
				if (bit & check) {
					tSum += taste[t];
					cSum += cal[t];
				}
			}
			if (cSum <= L) {
				ans = max(ans, tSum);
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}
}