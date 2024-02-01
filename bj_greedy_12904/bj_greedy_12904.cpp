#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//뒤에 a빼기
void remove_a(string& str) {
	str.pop_back();
}

//b빼고 뒤집기 
void remove_b_reverse(string& str) {
	str.pop_back();
	reverse(str.begin(), str.end());
}

int main(void) {
	string s, t;
	cin >> s;
	cin >> t;
	//t 문자열의 뒤에서부터 고려하기 
	//a빼기, b빼고 뒤집기 이런식으로 거꾸로 생각하기 .

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