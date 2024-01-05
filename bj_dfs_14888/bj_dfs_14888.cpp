#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 99999999999; 

vector <int> v;

int result_max = -INF;
int result_min = INF;

void dfs(int plus, int minus, int multi, int divide, int result, int cnt) {
	if (plus < 0 || minus < 0 || multi < 0 || divide < 0) return;

	if (cnt == v.size()) {
		result_max = max(result, result_max);
		result_min = min(result, result_min);
		return;
	}

	dfs(plus - 1, minus, multi, divide, result + v[cnt], cnt + 1);
	dfs(plus, minus - 1, multi, divide, result - v[cnt], cnt + 1);
	dfs(plus, minus, multi - 1, divide, result * v[cnt], cnt + 1);
	dfs(plus, minus, multi, divide - 1, result / v[cnt], cnt + 1);
}
int main() {
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		v.push_back(a);
	}

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	dfs(a, b, c, d, v[0], 1);

	cout << result_max << endl;
	cout << result_min << endl;

	return 0;

}