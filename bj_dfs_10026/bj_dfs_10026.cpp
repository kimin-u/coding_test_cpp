#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int result = 0;
int result2 = 0;

void dfs(const vector<vector<char>>& graph, vector<vector<bool>>& visited, int i, int j, int n) {
	visited[i][j] = true;
	char tmp = graph[i][j];


	//»óÇÏÁÂ¿ì ÀÎµ¦½º
	if (i - 1 >= 0) {
		char sang = graph[i - 1][j];
		if ((sang == tmp) && (visited[i - 1][j] == false))
			dfs(graph, visited, i - 1, j, n);
	}

	if (i + 1 < n) {
		char ha = graph[i + 1][j];
		if ((ha == tmp) && (visited[i + 1][j] == false))
			dfs(graph, visited, i + 1, j, n);
	}

	if (j - 1 >= 0)
	{
		char jwa = graph[i][j - 1];
		if ((jwa == tmp) && (visited[i][j - 1] == false))
			dfs(graph, visited, i, j - 1, n);
	}

	if (j + 1 < n) {
		char woo = graph[i][j + 1];
		if ((woo == tmp) && (visited[i][j + 1] == false))
			dfs(graph, visited, i, j + 1, n);
	}
}

void dfs2(const vector<vector<char>>& graph, vector<vector<bool>>& visited, int i, int j, int n) {
	visited[i][j] = true;
	char tmp = graph[i][j];
	char tmp2;
	if (tmp == 'R')
		tmp2 = 'G';
	if (tmp == 'G')
		tmp2 = 'R';
	if (tmp == 'B')
		tmp2 = 'B';
	//»óÇÏÁÂ¿ì ÀÎµ¦½º
	if (i - 1 >= 0) {
		char sang = graph[i - 1][j];
		if (((sang == tmp) || (sang == tmp2)) && (visited[i - 1][j] == false))
			dfs2(graph, visited, i - 1, j, n);
	}

	if (i + 1 < n) {
		char ha = graph[i + 1][j];
		if (((ha == tmp) || (ha == tmp2)) && (visited[i + 1][j] == false))
			dfs2(graph, visited, i + 1, j, n);
	}

	if (j - 1 >= 0)
	{
		char jwa = graph[i][j - 1];
		if (((jwa == tmp) || (jwa == tmp2)) && (visited[i][j - 1] == false))
			dfs2(graph, visited, i, j - 1, n);
	}

	if (j + 1 < n) {
		char woo = graph[i][j + 1];
		if (((woo == tmp) || (woo == tmp2)) && (visited[i][j + 1] == false))
			dfs2(graph, visited, i, j + 1, n);
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<char>> graph(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		string tmpstring;
		cin >> tmpstring;
		for (int j = 0; j < n; j++) {
			graph[i][j] = tmpstring[j];
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				result++;
				dfs(graph, visited, i, j, n);
			}
		}
	}

	vector<vector<bool>> visited2(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j] == false) {
				result2++;
				dfs2(graph, visited2, i, j, n);
			}
		}
	}

	cout << result << " " << result2;
	return 0;
}