//레벤시테인거리 구하기 dp table; 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(string s1, string s2);

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int result = edit_distance(s1, s2);

	cout << result;

	return 0;
}

int edit_distance(string s1, string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1));
	//dp 초기화;
	dp[0][0] = 0;
	for (int i = 1; i <= n1; i++)
		dp[i][0] = dp[i - 1][0] + 1;
	for (int j = 1; j <= n2; j++) 
		dp[0][j] = dp[0][j - 1] + 1;

	//dp update;
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {		
			if (s1[i-1] == s2[j-1])
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] });
			else
				dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
		}
	}

	//이하 출력문 
	int i, j;
	cout << "###DP TABLE###\n";
	for (i = -1; i <= n1; i++) {
		if (i== -1 || i==0)
			cout<<"  ";
		if (i != -1 && i != 0)
			cout << s1[i - 1] << " ";
		for (j = -1; j <= n2; j++) {
			if (i >= 0 && j >= 0) {
				cout << dp[i][j] << " ";
				continue;
			}
			if (i == -1) {
				if (j == -1 || j == 0) {
					cout << " "; continue;
				}
				cout << s2[j - 1] << " "; continue;
			}
		}
		
		cout << endl;
	}
	
	cout << endl;
	return dp[n1][n2];
}