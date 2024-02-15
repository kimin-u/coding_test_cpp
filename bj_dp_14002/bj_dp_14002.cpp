#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
	cin >> n;
	vector<int> lst(n);

	for (int i = 0; i < n; i++)
		cin >> lst[i];

	vector<int> dp(n);
	dp[0] = 1;

	vector<vector<int>> result(n);
	result[0].push_back(lst[0]);

	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (lst[i] > lst[j]) {
				int tmp = dp[i];
				dp[i] = max(dp[i], dp[j] + 1);
				if (tmp != dp[i]) {
					result[i] = result[j];
					
				}
			}
		}
		result[i].push_back(lst[i]);
	}

	int idx = -1;
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max){
			max = dp[i];
			idx = i;
		}
	}

	cout << max << endl;
	for (int i = 0; i < result[idx].size(); i++) {
		cout << result[idx][i] << " ";
	}
	return 0;
}