#include <iostream>
#include <queue>

#define INTMIN -200000
using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	//���� �Էµ� ���߿� ���� ��� ���� ����ϱ� 
	//¦������ �Էµ� ��쿡�� ���� �� ����ϱ�
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int prev = INTMIN;

	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		pq.push(k);
		if (i % 2 == 1) {
			int tmp = pq.top();
			pq.pop();

			if (prev < tmp) {
				prev = tmp;
			}
		}
		cout << prev << "\n";
	}
}