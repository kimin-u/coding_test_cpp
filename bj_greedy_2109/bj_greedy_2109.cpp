#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first > b.first) return true;
		return false;
	}
	return false; 
}

int main(void) {
	cin >> n;
	
	vector<pair<int, int>> lst(n);
	for (int i = 0; i < n; i++)
		cin >> lst[i].first >> lst[i].second;

	sort(lst.begin(), lst.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		pq.push(lst[i].first);
		if (lst[i].second < pq.size()) {
			pq.pop();
		}
	}

	int result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
	return 0;
}