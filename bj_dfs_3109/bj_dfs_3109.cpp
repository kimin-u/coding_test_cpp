#include <iostream>
#include <string>
#include <vector>

using namespace std;

int r, c;

vector<vector<char>> graph;
vector<vector<bool>> visited;

vector<int> di = { -1,0,1 };
vector<int> dj = { 1,1,1 };

int result = 0;


bool dfs(int i, int j) {
	visited[i][j] = true;


	for (int k = 0; k < 3; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if ((ni < 0) || (ni >= r) || (nj < 0) || (nj >= c)) continue;

		if (graph[ni][nj] != 'x' && visited[ni][nj]== false) {
			if (nj == c - 1) { 
				result++; 
				//visited[ni][nj] = true;
				return true;
			}

			if (dfs(ni, nj)) {
				//visited[i][j] = true;
				return true;
			}
			
		}
	}
	return false;
}

int main(void)
{
	cin >> r >> c;
	graph.assign(r, vector<char>(c));
	visited.assign(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			graph[i][j] = s[j];
		}
	}

	for (int i = 0; i < r; i++) {
		visited[i][0] = true;
		dfs(i, 0);
	}

	cout << result;
	return 0;
}