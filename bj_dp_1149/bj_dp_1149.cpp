#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void)
{
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++)
		cin >> graph[i][0] >> graph[i][1] >> graph[i][2];

	//이전집이랑 색이 달라야함
	vector<vector<int>> dp(n, vector<int>(3));

	dp[0][0] = graph[0][0]; dp[0][1] = graph[0][1]; dp[0][2] = graph[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + graph[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + graph[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][2];
	}

	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}
