#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(const vector<int>& list, vector<int>& dp, int n);

int main(void)
{
	int n; cin >> n;
	vector<int> list(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> list[i];
	}

	//dp[i] = i번째 병사를 포함했을때 최대 병사의 수  // 이후는 고려하지 않음 ,i까지만!!
	// dp[i] = i번째 이전에 내림차순 정렬된 리스트의 길이 +1 을 의미 ""!!!! 
	//dp[i]를 구할때는 i번째 이전의 병사들은 전투력이 커야하고 내림차순 정렬되어야 함
	//그 이후에는 전투력이 더 작아야 한다 . + 내림차순 정렬되어 있어야 함 .
	//이전의 병사들의 전투력이 큰걸 생각할려면 > 

	vector<int> dp(n + 1, 0);

	solution(list, dp, n);
	
	int maxdp = *max_element(dp.begin(), dp.end());

	cout << n-maxdp;
	return 0;
}

void solution(const vector<int>& list, vector<int>& dp, int n) {
	dp[1] = 1; 
	int i, j;
	for (i = 2; i <= n; i++) {
		int maxlen = 0;
		for (j = i-1; j >= 1 ; j--) {
			if (list[j] > list[i]) {
				maxlen = max(maxlen, dp[j]);
			}
		}
		//1번부터  j번째까지 내림차순 정렬된 리스트의 길이 +1 = dp[i];
		dp[i] = maxlen + 1;

	}
}
