#include <iostream>
#include <vector>

using namespace std;

int t;

int main(void) {
	cin >> t;

	while (t--) {
		int n; cin >> n;


		vector<pair<int, int >> dp(n + 1);
		dp[0] = { 1, 0 };
		dp[1] = { 0,1 };

		for (int i = 2; i <= n; i++) {
			dp[i].first = dp[i - 2].first + dp[i - 1].first;
			dp[i].second = dp[i - 2].second + dp[i - 1].second;
		}

		cout << dp[n].first << " " << dp[n].second << endl;
	}
	return 0;
}