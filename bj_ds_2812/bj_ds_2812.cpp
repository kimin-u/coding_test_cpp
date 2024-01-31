#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int n, k;

int main(void) {
	cin >> n >> k;

	stack<int> st;
	int cnt = 0;
	
	vector<int> lst; 
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		lst.push_back(int(s[i] - '0'));
	}

	int i = 0;
	while (i<n) {
		//if (cnt == k) break;

		int tmp = lst[i];

		while (!st.empty() && st.top() < tmp && cnt < k) {
			st.pop();
			cnt++;
		}

		st.push(tmp);
		i++;
	}

	while (i < n) {
		st.push(lst[i]);
		i++;
	}
	while (cnt < k && !st.empty()) {
		st.pop();
		cnt++;
	}

	stack<int> result;
	while (!st.empty()) {
		result.push(st.top());
		st.pop();
	}
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	return 0;
}