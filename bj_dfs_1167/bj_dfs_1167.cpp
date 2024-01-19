#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;

int v;
int maxDistanceNode;
int maxDistance;

void dfs(int i, int distance) {
    visited[i] = true;

    if (distance > maxDistance) {
        maxDistance = distance;
        maxDistanceNode = i;
    }

    for (const auto& neighbor : graph[i]) {
        int nextNode = neighbor.first;
        int edgeWeight = neighbor.second;
        if (!visited[nextNode]) {
            dfs(nextNode, distance + edgeWeight);
        }
    }
}

int findTreeDiameter() {
    visited.assign(v, false);
    maxDistance = 0;
    dfs(0, 0);

    visited.assign(v, false);
    maxDistance = 0;
    dfs(maxDistanceNode, 0);

    return maxDistance;
}



int main(void)
{
	cin >> v;

	graph.assign(v, vector<pair<int, int>>());

	int u, weight;
	int tmp;
	for (int i = 0; i < v; i++) {
		cin >> tmp;
		while (true) {
			cin >> u;
			if (u == -1) break;
			cin >> weight;
			graph[tmp - 1].push_back(make_pair(u, weight));
		}
	}

    int result = findTreeDiameter();
    cout << result;

	
	return 0;
}