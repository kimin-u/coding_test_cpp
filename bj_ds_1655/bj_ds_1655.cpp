#include <iostream>
#include <queue>

#define INTMIN -200000
using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	priority_queue<int, vector<int>, less<int> > max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;


	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		int len_max = max_pq.size();
		int len_min = min_pq.size();

		if (len_max == len_min) {
			max_pq.push(tmp);
		}
		else min_pq.push(tmp);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > min_pq.top()) {
				int a = max_pq.top(); max_pq.pop();
				int b = min_pq.top(); min_pq.pop();

				max_pq.push(b);
				min_pq.push(a);
			}
		}

		cout << max_pq.top() << "\n";
	}

	return 0;




}
