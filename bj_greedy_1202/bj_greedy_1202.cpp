#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<pair<int, int> > dia;
vector<int> carrier;

bool compare_dia(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	return false;

}

bool compare_carrier(int a, int b) {
	if (a < b) return true;
	return false;
}

int main(void)
{
	cin >> n >> k;
	dia.assign(n, { 0,0 });
	carrier.assign(k,0);
	for (int i = 0; i < n; i++) {
		cin >> dia[i].first >> dia[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> carrier[i];
	}

	//value�� �ִ�� �ؾ��� 
	//value �������� ������ �ϰ� ���濡 �� �� ������ �߰��ϰ� �ƴϸ� �������� �Ѿ�� 
	sort(dia.begin(), dia.end(), compare_dia);
	sort(carrier.begin(), carrier.end(), compare_carrier);

	priority_queue<int> pq;

	int result = 0;
	vector<bool> visit(k, false);

	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && dia[idx].first < carrier[i]) {
			pq.push(dia[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	
	cout << result;
	return 0;
}