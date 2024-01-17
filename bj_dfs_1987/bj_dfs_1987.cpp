//자주사용하는건 함수내부에서 정의하게끔 하지 말자.
//특히 재귀일때는 더더욱


#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
using namespace std;

int r, c;
vector<vector<char>> graph;
vector<int> visited(26, 0);
int result = 0;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

void dfs(int i, int j, int length)
{
	result = max(result, length);

	
	//char tmp = graph[i][j];
	//visited[tmp - 'A'] = true;

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];

		if ((ni < 0) || (ni >= r) || (nj < 0) || (nj >= c)) continue;
		
		int next = graph[ni][nj] - 'A';
		if (visited[next] == false) {
			visited[next] = true;

			dfs(ni, nj, length + 1);
			visited[next] = false;

		}
	}
	//visited[tmp - 'A'] = false;
}
int main(void)
{
	cin >> r >> c;
	graph.assign(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin>>graph[i][j];
		}
	}
	visited[graph[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << result;
	return 0;
}