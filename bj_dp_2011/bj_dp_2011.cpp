#include <iostream>
#include <vector>
#include <string>

#define INTMAX 1000000

using namespace std;


//¾ËÆÄºª :1~ 26 (26°³);

int main(void) {
	string s;
	cin >> s;

	int n = s.length();

	vector<int> dp(n + 1);

	dp[0] = 1;
	if (s[0] == '0') {
		cout << 0;
		return 0;
	}
	dp[1] = 1;


	for (int i = 2; i < n + 1; i++) {
		if (s[i - 1] != '0') {
			dp[i] = dp[i - 1] % INTMAX;
		}

		int tmp = (s[i-2] -'0') * 10 + (s[i-1] -'0');

		if (tmp >= 10 && tmp <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % INTMAX;
		}
	}

	/*for (int i = 1; i <= n; i++) {
		cout << "dp[" << i << "] : (" << dp[i].first << ", " << dp[i].second << ")" << endl;
	}*/

	cout << dp[n];
	return 0;

}
