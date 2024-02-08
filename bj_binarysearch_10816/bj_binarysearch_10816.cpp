#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int main(void) {
	cin >> n;
	vector<int> lst(20000001,0);

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		lst[tmp + 10000000]++;
	}
	cin >> m;
	vector<int> cnt(m);
	for (int i = 0; i < m; i++) {
		cin >> cnt[i];
	}

	vector<int> result(m);
	for (int i = 0; i < m; i++) {
		result[i] = lst[cnt[i] + 10000000];
	}

	for (int i = 0; i < m; i++) {
		cout << result[i] << " ";
	}
}

