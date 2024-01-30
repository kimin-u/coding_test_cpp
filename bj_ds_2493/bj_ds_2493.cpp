#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

int main(void) {
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++)
		cin >> array[i];

	stack<pair<int, int> > st;
	stack<int> result;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top().first <= array[i]) st.pop();

		if (st.empty()) cout << 0 << " ";

		else cout << st.top().second << " ";

		st.push(make_pair(array[i], i + 1));
	}
	return 0;
}