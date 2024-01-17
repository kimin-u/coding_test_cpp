#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<vector<int>>& graph, vector<vector<int>>& memo, int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) {
        return 1;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int result = 0;
    int tmp = graph[i][j];
    vector<int> di = { -1, 1, 0, 0 };
    vector<int> dj = { 0, 0, -1, 1 };

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && graph[ni][nj] < tmp) {
            result += dfs(graph, memo, ni, nj, m, n);
        }
    }

    memo[i][j] = result;
    return result;
}

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph;

    for (int i = 0; i < m; i++) {
        vector<int> tmp(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> tmp[j];
        }
        graph.push_back(tmp);
    }

    vector<vector<int>> memo(m, vector<int>(n, -1));
    int result = dfs(graph, memo, 0, 0, m, n);

    cout << result;

    return 0;
}
