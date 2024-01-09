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

	//dp[i] = i��° ���縦 ���������� �ִ� ������ ��  // ���Ĵ� ������� ���� ,i������!!
	// dp[i] = i��° ������ �������� ���ĵ� ����Ʈ�� ���� +1 �� �ǹ� ""!!!! 
	//dp[i]�� ���Ҷ��� i��° ������ ������� �������� Ŀ���ϰ� �������� ���ĵǾ�� ��
	//�� ���Ŀ��� �������� �� �۾ƾ� �Ѵ� . + �������� ���ĵǾ� �־�� �� .
	//������ ������� �������� ū�� �����ҷ��� > 

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
		//1������  j��°���� �������� ���ĵ� ����Ʈ�� ���� +1 = dp[i];
		dp[i] = maxlen + 1;

	}
}
