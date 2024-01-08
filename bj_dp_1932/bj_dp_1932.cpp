#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<vector<int>>& dp, const vector<vector<int>>& triangle, int n);

int main(void)
{
	int n; cin >> n;
	int result = -1;
	vector<vector<int>> triangle;
	vector<int> tmptri;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int tmp; cin >> tmp;
			tmptri.push_back(tmp);
		}
		triangle.push_back(tmptri);
		tmptri.clear();
	}

	vector<vector<int>> dp(n, vector<int>(n, -1));

	solution(dp, triangle, n);

	for (int i = 0; i < n; i++) {
		if (result < dp[n-1][i])
			result = dp[n-1][i];
	}

	cout << result;

	return 0;
}

void solution(vector<vector<int>>& dp, const vector<vector<int>>& triangle, int n) {
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else
				dp[i][j] = max(dp[i-1][j]+ triangle[i][j] , dp[i - 1][j - 1] + triangle[i][j]);

		}
	}
}