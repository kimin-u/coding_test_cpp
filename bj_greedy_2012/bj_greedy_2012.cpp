#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main(void) {
	cin >> n;
	vector<int> grade(n);
	for (int i = 0; i < n; i++)
		cin >> grade[i];

	sort(grade.begin(), grade.end());

	long long int result = 0;
	for (int i = 0; i < n; i++) {
		result += abs((i + 1) - grade[i]);
	}
	cout << result;
}