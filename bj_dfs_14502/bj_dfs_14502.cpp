#include <iostream>
#include <vector>


using namespace std;

int result = 0;

void make_wall(vector<vector<int>>& graph, int wallcnt);
void dfs_spread(vector<vector<int>>& graph, int i, int j);
int result_score(const vector<vector<int>>& graph);

int main(void) {
    //input;
    int n, m;
    cin >> n >> m;

    //graph 생성 ; 입력받기;
    vector<vector<int>> graph(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        int tmp;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    make_wall(graph, 3);
    cout << result;

    return 0;
}

void make_wall(vector<vector<int>>& graph, int wallcnt)
{
    //벽생성이 끝남 >  dfs 바이러스 확산을 진행해야함 .
    if (wallcnt == 0) {
        vector<vector<int>> tmp(graph.size(), vector<int>(graph[0].size()));
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                tmp[i][j] = graph[i][j];
            }
        }
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < tmp[0].size(); j++) {
                if (tmp[i][j] == 2) {
                    dfs_spread(tmp, i, j);
                }
            }
        }
        result = max(result, result_score(tmp));
    }
    //벽 더 생성해야 되는 경우
    else {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                if (graph[i][j] == 0) {
                    graph[i][j] = 1;
                    wallcnt--;
                    make_wall(graph, wallcnt);
                    graph[i][j] = 0;
                    wallcnt++;
                }
            }
        }
    }
}
void dfs_spread(vector<vector<int>>& tmp, int i, int j)
{
    vector<int> di = { -1,1,0,0 };
    vector<int> dj = { 0,0,-1,1 };
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if ((ni < 0) || (ni >= tmp.size()) || (nj < 0) || (nj >= tmp[0].size())) continue;
        if (tmp[ni][nj] == 0) {
            tmp[ni][nj] = 2;
            dfs_spread(tmp, ni, nj);
        }
    }
}
int result_score(const vector<vector<int>>& graph)
{
    int tmp = 0;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[0].size(); j++) {
            if (graph[i][j] == 0) {
                tmp++;
            }
        }
    }
    return tmp;
}