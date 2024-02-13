#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> lst(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> lst[i];
	}
	//�ѹ��� �ϳ� �Ǵ� �ΰ� ������ 
	//���� �������� ��� �ȵ�

	//dp[i] = i��° ��� ������ �ִ��� �ǹ�;
	vector<int> dp(301);
	dp[0] = 0;
	dp[1] = lst[1];
	dp[2] = lst[1] + lst[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + lst[i], dp[i - 3] + lst[i - 1] + lst[i]);
	}

	cout << dp[n];

	return 0;

}