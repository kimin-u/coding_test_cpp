#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;

int main(void) {
	cin >> h >> w;
	
	vector<int> graph(w);
	for (int i = 0; i < w; i++) {
		cin >> graph[i];
	}


	int result=0;
	for (int i = 1; i < w - 1; i++) {
		//i보다 작은 위치~ 에서 제일 큰값 찾기
		int leftmax = 0;
		for (int j = 0; j < i; j++) {
			if (graph[j] > leftmax)
				leftmax = graph[j];
		}
		//i+1~이후로 가장 큰 값 찾기
		int rightmax = 0;
		for (int j = i + 1; j < w; j++) {
			if (graph[j] > rightmax)
				rightmax = graph[j];
		}

		int tmp = min(leftmax, rightmax) - graph[i];
		if (tmp < 0) tmp = 0;
		result += tmp;

	}

	cout << result;
	return 0;
}