#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int>& t, const vector<int>& p, vector<int>& dp);
int main(void)
{
	int n; cin >> n;
	vector<int> t(n+1,0);
	vector<int> p(n+1,0);

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	vector<int> dp(n+1, 0);

	solution(t, p, dp);

	cout << *max_element(dp.begin(), dp.end());

	/*cout << endl;
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}*/
	return 0;
}

void solution(vector<int>& t, const vector<int>& p, vector<int>& dp) {
	int n = dp.size()-1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (t[j] + j <= i && i+t[i] <= n+1) {
				dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
	}
}