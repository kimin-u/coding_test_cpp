#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;

int n;
int tmpresult;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int dfs(int i, int j){
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 1;
	int tmp = graph[i][j];
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= n)) continue;
	
		if (graph[ni][nj] > tmp){
			dp[i][j] = max(dp[i][j], dfs(ni, nj)+1);
		}
	}
	return dp[i][j];

}


int main(void)
{
	cin >> n;
	graph.assign(n, vector<int>(n));
	dp.assign(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int result = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, dfs(i, j));
		}
	}
	
	cout << result;
	return 0;
}