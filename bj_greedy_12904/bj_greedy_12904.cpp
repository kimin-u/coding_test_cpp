#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//�ڿ� a����
void remove_a(string& str) {
	str.pop_back();
}

//b���� ������ 
void remove_b_reverse(string& str) {
	str.pop_back();
	reverse(str.begin(), str.end());
}

int main(void) {
	string s, t;
	cin >> s;
	cin >> t;
	//t ���ڿ��� �ڿ������� ����ϱ� 
	//a����, b���� ������ �̷������� �Ųٷ� �����ϱ� .

	for (int i = t.length() - 1; i >= 0; i--) {
		if (t[i] == 'A') {
			remove_a(t);
		}
		else if (t[i] == 'B') {
			remove_b_reverse(t);
		}

		if (t.length() == s.length()) {
			if (t == s) {
				cout << 1;
				return 0;
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
}