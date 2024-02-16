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
		if (isoper(str[i])) { //연산자인 경우
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
				//지금 str[i]랑 , stack top의 연산자랑 우선순위 비교 ;
				//str[i]가 우선순위가 높으면 그만!
				//str[i]가 낮으면 이미 스택에 있는것들 result string으로 옮기기 
				if (priority(st, str[i])) {
					//stack에 있는거 빼야함
					result += st.top();
					st.pop();
				}

				else break;
			}

			if (str[i] == ')') continue;

			st.push(str[i]);

		}

		else { //피연산자인 경우
			//바로 result string으로 옮기면 된다.
			result += str[i];
		}
	}


	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result;
}

