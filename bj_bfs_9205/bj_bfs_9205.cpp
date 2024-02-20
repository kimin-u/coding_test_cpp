#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<pair<int, int>>& graph, int n) {
    queue<pair<int, int>> q;
    vector<bool> visited(n + 2, false);  // 방문 여부를 저장하는 배열 추가
    q.push({ graph[0].first, graph[0].second });
    visited[0] = true;

    while (!q.empty()) {
        int tmpi = q.front().first;
        int tmpj = q.front().second;
        q.pop();

        for (int i = 1; i < n + 2; i++) {
            if (!visited[i]) {
                int ni = graph[i].first;
                int nj = graph[i].second;
                int distance = abs(tmpi - ni) + abs(tmpj - nj);

                if (distance <= 1000) {
                    q.push({ ni, nj });
                    visited[i] = true;
                }
            }
        }
    }

    if (visited[n + 1]) {
        cout << "happy" << endl;
    }
    else {
        cout << "sad" << endl;
    }
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n; // 편의점 개수

        vector<pair<int, int>> graph;
        for (int i = 0; i < n + 2; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            graph.push_back({ tmp1, tmp2 });
        }

        bfs(graph, n);
    }
    return 0;
}
