#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, h;
vector<vector<vector<int>>> graph;
queue < pair< pair<int, pair<int, int>>, int>> q;

vector<int> di = { 0, 0, 0, 0, -1, 1 };
vector<int> dj = { -1, 1, 0, 0, 0, 0 };
vector<int> dk = { 0, 0, -1, 1, 0, 0 };

int bfs(void) {

	int result = 0;
	while (!q.empty()) {
		int tmpi = q.front().first.first;
		int tmpj = q.front().first.second.first;
		int tmpk = q.front().first.second.second;
		int day = q.front().second;

		result = max(result, day);

		q.pop();
		
		for(int k=0; k<6; k++){	
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];
			int nk = tmpk + dk[k];

			if ((ni < 0) || (ni >= h) || (nj < 0) || (nj >= n) || (nk < 0) || (nk >= m)) continue;

			if (graph[ni][nj][nk] == 0) {
				graph[ni][nj][nk] = 1;
				q.push({ {ni,{nj,nk}},day + 1 });
			}
			
		}

	}
	return result;
}

bool checkall(void) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (graph[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	
	graph.assign(h, vector<vector<int>>(n, vector<int>(m)));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) {
					q.push({ { i,{j,k} },0 });
				}
			}
		}
	}


	if (checkall()) {
		cout << 0;
		return 0;
	}
	int result = bfs();

	if (checkall()) {
		cout << result;
		return 0;
	}
	else {
		cout << -1;
		return 0;
	}
}