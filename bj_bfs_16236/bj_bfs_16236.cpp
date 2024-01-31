#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
queue<pair<pair<int, int>, int>> q;
vector<vector<int>> graph;
vector<vector<bool>> visited;

pair<int, int> shark;
int sharkstate = 2;
int food = 0;

vector<int> di = { -1,0,0,1 };
vector<int> dj = { 0,-1,1,0 };

int result = 0;

bool bfs(void) {
    visited.assign(n, vector<bool>(n, false));
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(shark, 0));
    visited[shark.first][shark.second] = true;

    vector<pair<pair<int, int>, int>> candidates;  // 먹을 수 있는 물고기 후보들

    while (!q.empty()) {
        int tmpi = q.front().first.first;
        int tmpj = q.front().first.second;
        int day = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = tmpi + di[k];
            int nj = tmpj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            if (graph[ni][nj] > sharkstate) continue;
            if (visited[ni][nj]) continue;

            q.push(make_pair(make_pair(ni, nj), day + 1));
            visited[ni][nj] = true;

            if (graph[ni][nj] != 0 && graph[ni][nj] < sharkstate) {
                candidates.push_back(make_pair(make_pair(ni, nj), day + 1));
            }
        }
    }

    if (!candidates.empty()) {
        sort(candidates.begin(), candidates.end(),
            [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
                if (a.second == b.second) {
                    if (a.first.first == b.first.first) {
                        return a.first.second < b.first.second;
                    }
                    return a.first.first < b.first.first;
                }
                return a.second < b.second;
            });

        shark = candidates[0].first;
        graph[shark.first][shark.second] = 0;
        result += candidates[0].second;
        food++;
        return true;
    }

    return false;
}

int main(void)
{
	cin >> n;
	graph.assign(n, vector<int>(n));
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				graph[i][j] = 0;
				shark = make_pair(i, j);
			}
		}
	}

	while (bfs()) {
		if (food == sharkstate) {
			sharkstate++;
			food = 0;
			//cout << "SHARK : " << sharkstate << endl;
		}
	}


	cout << result;
	return 0;
}