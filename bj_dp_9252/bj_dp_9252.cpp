#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<vector<int>> dp;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	
	dp.assign(len1 + 1, vector<int>(len2 + 1, 0));

	

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

	string result = "";

	//역추적 해야;
	int i = len1, j = len2;
	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			result = s1[i - 1] + result;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	if (dp[len1][len2] != 0) {
		cout << dp[len1][len2] << endl;
		cout << result;
	}
	else {
		cout << dp[len1][len2];
	}
	return 0;
}