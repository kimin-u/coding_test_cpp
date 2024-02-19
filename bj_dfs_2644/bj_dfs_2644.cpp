#include <iostream>
#include <vector>

using namespace std;

int n, m;
int answer;

void dfs(const vector<vector<int>>& graph, vector<int>& visited, int i, int j, int result) {
	visited[i] = 1;
	if (i == j) {
		answer = result;
		return;
	}

	for (int k = 0; k < graph[i].size(); k++) {
		if (visited[graph[i][k]] == 0) {
			dfs(graph, visited, graph[i][k], j, result+1);
		}
	}
	

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<vector<int>> graph(n);
	vector<int> visited(n, 0);

	int start, enda;
	cin >> start >> enda;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1 - 1].push_back(tmp2 - 1);
		graph[tmp2 - 1].push_back(tmp1 - 1);
	}

	dfs(graph, visited, start-1,enda-1, 0);

	if (answer != 0) {
		cout << answer;
	}
	else { cout << -1; }

}