#include <iostream>
#include <vector>

using namespace std;

vector<bool> dp;

bool solve(int n) {
	if (n == 1 || n == 3) return true;
	if (dp[n] != -1) return dp[n];

	else {
		if (solve(n - 2) == true) dp[n] = true;
		else if (solve(n - 4) == true) dp[n] = true;
		else if (solve(n - 6) == true) dp[n] = true;
		else dp[n] = false;
		return dp[n];
	}
}
int main(void)
{
	int n; cin >> n;
	dp.assign(n + 1, false);
	if (solve(n) == true) cout << "SK" << endl;
	else cout << "CY" << endl;
}