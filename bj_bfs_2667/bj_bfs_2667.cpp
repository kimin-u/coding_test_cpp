#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int apartment = 1; 

void bfs(int i, int j, vector<vector<int>>& visited) {
	visited[i][j] = 1; 
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty()) {
		int tmpi = q.front().first;
		int tmpj = q.front().second;
		q.pop();

		graph[tmpi][tmpj] = apartment;

		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= n)) continue;

			if (graph[ni][nj] != 0 && visited[ni][nj] == 0) {
				visited[ni][nj] = 1;
				q.push({ ni,nj });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	graph.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j] = int(s[j] - '0');
		}
	}

	vector<vector<int>> visited(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] != 0 && visited[i][j] == 0) {
				bfs(i, j, visited);
				apartment++;
			}
		}
	}

	cout << apartment - 1 << endl;

	vector<int> result;


	for (int k = 1; k < apartment; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == k) {
					cnt++;
				}
			}
		}

		result.push_back(cnt);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	
	return 0;
}