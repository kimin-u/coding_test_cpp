#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first	) {
		if (a.second < b.second) return true;
		return false;
	}
	return false;
}

int main(void) {
	int n; cin >> n;
	vector<pair<int, int>> schedule;

	for(int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		schedule.push_back({ s,t });
	}

	sort(schedule.begin(), schedule.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		if (!pq.empty()) {
			if (pq.top() <= schedule[i].first) {
				pq.pop();
			}
		}

		pq.push(schedule[i].second);

	}

	cout << pq.size();
	return 0;
}