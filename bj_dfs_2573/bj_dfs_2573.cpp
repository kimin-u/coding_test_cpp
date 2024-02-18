#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

//visited 2�������� false�� �ʱ�ȭ �ϴ� �Լ�
void resetvisit() {
	visited.assign(n, vector<int>(m, 0));
}

// (i,j)������ 0�� ��� �ִ��� Ȯ���ϴ� �Լ�. 
int zerocnt(int i, int j) {
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];

		
		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

		if (graph[ni][nj] == 0) cnt++;
	}
	return cnt;
}

//1���� ������ ǥ���� melt �Լ� 
void melt(void) {
	vector<vector<int>> cnt(n, vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) {
				cnt[i][j] = zerocnt(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] - cnt[i][j] < 0){
				graph[i][j] = 0;
				continue;
			}
			graph[i][j] = graph[i][j] - cnt[i][j];
		}
	}
}

//graph����Լ� (for debug);
void showgraph(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int i, int j) {
	visited[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];


		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

		if (graph[ni][nj] != 0 && visited[ni][nj] == 0)
			dfs(ni, nj);
	}
}

bool checkseparte(void) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] ==0 && graph[i][j] != 0){
				dfs(i, j);
				cnt++;
				if (cnt >= 2) return true;
			}
		}
	}
	return false;
}

bool allzero(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) return false;
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	graph.assign(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	int year = 0;
	while (true) {
		//1��. ���� �и��Ǿ����� üũ�ϱ�
		resetvisit();
		if (checkseparte()) {
			cout << year;
			return 0;
		}
		//0��, ��� ������ ��ҵ���~
		if (allzero()) {
			cout << 0;
			return 0;
		}

		//2��. �ȵǾ����� ���̰� ������ ����
		melt();
	/*	showgraph();
		cout << endl;*/
		year++;
	}


	return 0;
}