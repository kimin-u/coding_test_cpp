#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool compare(int a, int b) {
	if (a > b) return true;
	return false;
}

int main(void) {
	cin >> n;
	vector<int> neg;
	vector<int> pos;
	int zerocnt = 0;
	int onecnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp < 0) neg.push_back(tmp);
		else if (tmp == 0) zerocnt++;
		else if (tmp == 1) onecnt++;
		else pos.push_back(tmp);
	}
	//묶은 수는 곱해서 합으로 더한다 ;
	//음수, 양수는 서로 묶으면 손해고
	//음수, 음수는 두개 묶어야 하고,
	//0은 음수랑은 묶으면 좋고 ,양수랑은 묶으면 안좋다 .
	//1은 안 묶는게 이득이다 .

	//for dubug;
	cout << "NEG : ";
	for (int i = 0; i < neg.size(); i++) {
		cout << neg[i] << " ";
	}
	cout << endl;
	cout << "ZERO : " << zerocnt << endl;
	cout << "ONE : " << onecnt << endl;
	cout << "POS : ";
	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i] << " ";
	}
	cout << endl;







	int result = onecnt; //1은 그냥 더해줬고

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), compare);

	//음수의 개수가 홀수면 0에 제일 가까운 음수랑 0이랑 곱해줘야 한다 > 마지막꺼 삭제
	if (neg.size() % 2 != 0) {
		if (zerocnt >0)
			neg.erase(neg.begin() + neg.size() - 1);
	}
	int i;
	for (i = 0; i < neg.size(); i+=2) {
		if (i + 1 == neg.size()) break;
		result += (neg[i] * neg[i + 1]);
	}

	if (i == neg.size() - 1) result += neg[i];
	for (i = 0; i < pos.size(); i += 2) {
		if (i + 1 == pos.size()) break;
		result += (pos[i] * pos[i + 1]);
	}
	if (i == pos.size() - 1) result += pos[i];
	
	cout << result; 
	return 0;
}