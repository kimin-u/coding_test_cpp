#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void LCS(string s1, string s2) {
	int len1 = s1.length();
	int len2 = s2.length();

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[len1][len2];
}
int main(void)
{
	string s1, s2;

	cin >> s1 >> s2;

	LCS(s1, s2);

	return 0;

}