#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, queue<pair<pair<int, int>, int>> &q, int s);

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> graph(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		int tmp;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			graph[i][j] = tmp;
		}
	}

	int s, x, y;
	cin >> s >> x >> y;
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	queue<pair<pair<int, int>, int>> q;
	for (int x = 1; x <= k; x++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == x) {
					q.push(make_pair(make_pair(i, j),0));
				}
			}
		}
	}

	bfs(graph, q, s);

	//cout << endl;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	x--; y--;
	cout << graph[x][y];

}

void bfs(vector<vector<int>>& graph, queue<pair<pair<int, int>, int>>& q, int s){
	vector<int> di = { -1,1,0,0 };
	vector<int> dj = { 0,0,-1,1 };

	while (!q.empty()) {
		int tmpi = q.front().first.first;
		int tmpj = q.front().first.second;
		int tmps = q.front().second;
		if (tmps == s) break;
		int tmpvalue = graph[tmpi][tmpj];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= graph.size()) || (nj < 0) || (nj >= graph[0].size())) continue;

			if (graph[ni][nj] == 0) {
				graph[ni][nj] = tmpvalue;
				q.push(make_pair(make_pair(ni, nj),tmps+1));
			}
		}

	}
}