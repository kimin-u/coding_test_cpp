#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

int main(void) {
	cin >> n;
	stack<int> st;
	vector<int> array(n);
	for (int i = 0; i < n; i++)
		cin >> array[i];

	stack<int> result;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= array[i]) st.pop();

		if (st.empty()) result.push(-1);
		else result.push(st.top());

		st.push(array[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << result.top() << " ";
		result.pop();
	}

	return 0;
}