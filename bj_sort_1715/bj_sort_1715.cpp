//최소힙 구현하기 
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(void){
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> list;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		list.push(tmp);
	}

	int result = 0;
	while (true) {
		if (list.size() == 1) break;
		int tmpresult, tmp1, tmp2;
		tmp1 = list.top(); list.pop();
		tmp2 = list.top(); list.pop();
		tmpresult = tmp1 + tmp2;
		list.push(tmpresult);
		result += tmpresult;
	}

	cout << result;
	return 0;
}