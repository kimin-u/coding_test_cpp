#include <iostream>

using namespace std;

int A, B;
int cnt = 0;

int main(void)
{
	cin >> A >> B;
	int tmp = B;

	while (true) {
		if (tmp == A) {
			cout << cnt +1 ;
			return 0;
		}

		if (tmp < A) {
			cout << -1;
			return 0;
		}

		if (tmp % 10 == 1) {
			tmp -= 1;
			tmp /= 10;
			cnt++;
		}
		else if ( tmp % 2 ==0 ) {
			tmp /= 2;
			cnt++;
		}
		else {
			cout << -1; return 0;
		}
	}
	
}