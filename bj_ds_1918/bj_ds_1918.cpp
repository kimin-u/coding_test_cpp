#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isoper(char c) {
	if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/') return true;
	return false;
}
int score(char c) {
	if (c == '(') return 1;
	else if (c == '+' || c == '-') return 2;
	else if (c == '*' || c == '/') return 3;

}
bool priority(const stack<char> &st, char c) {
	if (score(st.top()) >= score(c)) {
		return true;
	}
	return false;
}

int main(void)
{
	string str; cin >> str;

	string result;
	
	stack<char> st;

	int strlen = str.length();
	for (int i = 0; i < strlen; i++) {
		if (isoper(str[i])) { //�������� ���
			while (!st.empty()) {
				if (str[i] == ')') {
					if (st.top() !='(')
						result += st.top();
					st.pop();
					continue;
				}
				if (str[i] == '(') {
					break;
				}
				//���� str[i]�� , stack top�� �����ڶ� �켱���� �� ;
				//str[i]�� �켱������ ������ �׸�!
				//str[i]�� ������ �̹� ���ÿ� �ִ°͵� result string���� �ű�� 
				if (priority(st, str[i])) {
					//stack�� �ִ°� ������
					result += st.top();
					st.pop();
				}

				else break;
			}

			if (str[i] == ')') continue;

			st.push(str[i]);

		}

		else { //�ǿ������� ���
			//�ٷ� result string���� �ű�� �ȴ�.
			result += str[i];
		}
	}


	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result;
}

