#include <iostream>
#include <queue>

using namespace std;

int n, m;


int main(void) {
	cin >> n >> m;
	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;


	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	while (m != 0) {
		m--;
		long long int sum = 0;
		sum += pq.top(); pq.pop();
		sum += pq.top(); pq.pop();
		pq.push(sum);
		pq.push(sum);
	}

	long long int result = 0;
	while (!pq.empty()) {
		result += pq.top(); pq.pop();
	}
	cout << result;

	return 0;
}