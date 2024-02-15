#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = s3.length();

	vector<vector<vector<int>>> dp(l1+ 1, vector<vector<int>>(l2+1, vector<int>(l3+1, 0)));

	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			for (int k = 1; k <= l3; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}

				else {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}
	cout << dp[l1][l2][l3];
	return 0;
}