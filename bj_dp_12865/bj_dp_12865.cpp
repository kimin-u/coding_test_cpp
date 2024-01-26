#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int knapsack(int k, int n, const vector<int>& weight, const vector<int>& value) {
    if ((k == 0) || (n == 0)) {
        return 0;
    }
    if (dp[k][n] != -1) return dp[k][n];

    dp[k][n] = knapsack(k, n - 1, weight, value);
    if (weight[n - 1] <= k) {
        dp[k][n] = max(dp[k][n], knapsack(k - weight[n - 1], n - 1, weight, value) + value[n - 1]);
    }
    return dp[k][n];
}

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> weight(n);
    vector<int> value(n);
    int tmp_w, tmp_v;

    for (int i = 0; i < n; i++) {
        cin >> tmp_w >> tmp_v;
        weight[i] = tmp_w;
        value[i] = tmp_v;
    }

    dp.assign(k + 1, vector<int>(n + 1, -1));
    int result = knapsack(k, n, weight, value);

    cout << result;

    return 0;
}
