#include <iostream>
#include <vector>
#include <algorithm>

#define INTMAX 2000000001
using namespace std;

int n;

int main(void) {
	cin >> n;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}

	vector<int> result(2);
	int min = INTMAX;

	sort(lst.begin(), lst.end());

	int start = 0;
	int end = n - 1;

	while (start < end) {
		int sum = lst[start] + lst[end];

		if (min > abs(sum)) {
			min = abs(sum);
			result[0] = lst[start];
			result[1] = lst[end];

			if (sum == 0)
				break;
		}

		if (sum < 0) start++;
		else end--;
	}

	cout << result[0] << " " << result[1];
	return 0;
}