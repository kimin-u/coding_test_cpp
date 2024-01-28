#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

int main(void) {
	cin >> n;
	priority_queue<int> pq;
	vector<int> lst;

	int goal;
	cin >> goal;

	for (int i = 1; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp >= goal) pq.push(tmp);
	}
	int result = 0;
	while (!pq.empty() && goal <= pq.top()) {
		int t = pq.top();
		pq.pop();
		t--;
		goal++;
		pq.push(t);
		result++;
	}

	cout << result;
	return 0;
	
}