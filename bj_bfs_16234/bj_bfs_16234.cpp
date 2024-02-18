#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, l, r;
queue<pair<int,int>> q;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<vector<pair<int,int>>> unit;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

///
void resetvisit(void) {
	visited.assign(n, vector<int>(n, 0));
}

int ab(int a) {
	if (a >= 0) return a;
	else 
		return -a;
}
//

void resetunit(void) {
	unit.clear();
}
void bfs(int i,int j) {
	q.push({ i,j });
	visited[i][j] = 1;

	bool nounit = true;
	while (!q.empty()) {
		int tmpi = q.front().first;
		int tmpj = q.front().second;
		q.pop();

		int people = graph[tmpi][tmpj];

		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= n)) continue;

			if (ab(graph[ni][nj] - people) >= l && ab(graph[ni][nj] - people) <= r && visited[ni][nj] ==0) {
				visited[ni][nj] = 1;
				q.push({ ni,nj });
				nounit = true;
			}
		}
	}

	if (nounit == false) return;

	vector<pair<int,int>> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 1) {
				tmp.push_back({ i,j });
			}
		}
	}
	
	unit.push_back(tmp);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l >> r;
	graph.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int day = 0;
	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				resetvisit();
				bfs(i, j);
			}
		}
		bool brake = true;
		for (int i = 0; i < unit.size(); i++) {
			if (unit[i].size() != 1) {
				brake = false;
				//1개가 아니여서 연합을 해야하는 경우임!
				int len = unit[i].size();
				int sum = 0;
				for (int j = 0; j < len; j++) {
					sum += graph[unit[i][j].first][unit[i][j].second];
				}

				int final = sum / len;

				for (int j = 0; j < len; j++) {
					graph[unit[i][j].first][unit[i][j].second] = final;
				}

			}
		}

		if (brake) {
			cout << day;
			break;
		}
		day++;
		resetunit();
	}
}