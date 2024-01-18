#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<vector<int>>> visited;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int bfs(int i, int j) {

	visited[i][j][0] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(i, j), 0));
	
	while (!q.empty()) {
		int tmpi = q.front().first.first;
		int tmpj = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		
		//끝에 도달 ; 종료조건;
		if (tmpi == n-1 && tmpj == m-1) return visited[tmpi][tmpj][wall];

		//distance++;
		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;
			
			if (graph[ni][nj] == 0 && visited[ni][nj][wall] == 0) {
				visited[ni][nj][wall] = visited[tmpi][tmpj][wall] + 1;
				q.push(make_pair(make_pair(ni, nj), wall));
			}

			if (graph[ni][nj] == 1 && wall == 0) {
				visited[ni][nj][1] = visited[tmpi][tmpj][wall] + 1;
				q.push(make_pair(make_pair(ni, nj), 1));
			}
		}
	}

	return -1;
}


int main(void)
{
	cin >> n >> m;
	graph.assign(n, vector<int>(m));
	visited.assign(n, vector<vector<int>>(m, vector<int>(2, 0)));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = int(s[j] - '0');
		}
	}
	
	int result = bfs(0, 0);

	cout << result;
	return 0;

}