#include <iostream>
#include <queue>

#define INTMIN -200000
using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	//여태 입력된 수중에 가장 가운데 수를 출력하기 
	//짝수개가 입력된 경우에는 작은 수 출력하기
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