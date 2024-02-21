#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

bool compare(pair<int, long long int> a, pair<int, long long int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second > b.second) return true;
		return false;
	}
	return false;
}

int main(void) {
	cin >> n;

	vector<pair<int, long long int>> lst(n);

	for (int i = 0; i < n; i++) {
		cin >> lst[i].first >> lst[i].second;
	}

	sort(lst.begin(), lst.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		pq.push(lst[i].second);
		if (lst[i].first < pq.size())
			pq.pop();
	}


	int result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result;
	return 0;
}