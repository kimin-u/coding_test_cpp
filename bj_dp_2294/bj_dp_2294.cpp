#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 999999

using namespace std;

int n, k;

vector<int> coin;
vector<int> dp;

int main(void)
{
    cin >> n >> k;
    coin.assign(n, 0);
    dp.assign(k + 1, INT_MAX); // 초기값을 INT_MAX로 설정

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 0; // 0원을 만드는데 필요한 동전의 개수는 0개

    for (int d = 1; d <= k; d++) {
        for (int i = 0; i < n; i++) {
            if (d - coin[i] >= 0 && dp[d - coin[i]] != INT_MAX) {
                dp[d] = min(dp[d], dp[d - coin[i]] + 1);
            }
        }
    }

    if (dp[k] == INT_MAX) {
        cout << -1; // 만들 수 없는 경우 -1 출력
    }
    else {
        cout << dp[k];
    }

    return 0;
}
