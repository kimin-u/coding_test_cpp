#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visited;
queue<pair<pair<int, int>,int>> q;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int bfs(void)
{
	int result = 0;
	while (!q.empty()) {
		int tmpi = q.front().first.first;
		int tmpj = q.front().first.second;
		int day = q.front().second;
		result = max(result,day);
		q.pop();
		//visited[tmpi][tmpj] = true;

		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;

			if (graph[ni][nj] == 0 && visited[ni][nj] == false) {
				graph[ni][nj] = 1;
				visited[ni][nj] = true;
				q.push(make_pair(make_pair(ni, nj), day + 1));
			}
		}
		result = day;
	}

	return result;
}

int main(void) {
	cin >> m>> n;
	graph.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			graph[i][j] = tmp;
			if (tmp == 1) {
				q.push(make_pair(make_pair(i, j), 0));
				visited[i][j] = true;
			}
		}
	}

	int reslt = bfs();

	bool all_tomato = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				all_tomato = false;
				break;
			}
		}
	}
	if (all_tomato) {
		cout << reslt;
	}
	else cout << "-1";

	return 0;

}