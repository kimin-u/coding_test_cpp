#include <iostream>
#include <string>
using namespace std;

//���� ���� �׷��� ���� / 2 ��;

int min_flip(string s) {
	int cnt= 1;
	int tmp= s[0];
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != tmp) {
			cnt++;
			tmp = s[i];
		}
	}

	return cnt / 2;
}
int main(void) {
	string s;
	cin >> s;

	cout<< min_flip(s);

	return 0;
}