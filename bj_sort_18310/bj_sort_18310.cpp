#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n; cin >> n;
	//�����ؼ� �߾Ӱ��� ����ϸ� �ȴ�.
	vector<int> house(n);
	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}
	sort(house.begin(), house.end());

	if (n % 2 == 0)
		cout << house[n / 2 - 1];
	else
		cout << house[n / 2];
	return 0;
}