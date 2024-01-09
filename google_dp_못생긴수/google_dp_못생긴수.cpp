//p381
//2, 3, 5만을 소인수로 가지는 수를 의미 n번째 못생긴 수 찾아라

#include <iostream>
#include <vector>

#define INF 10000000
#define maxlen 1001

using namespace std;

vector<int> uglylist(maxlen);


bool isugly(int i)
{
	vector<int> p = { 5,3,2 };

	for (int k = 0; k < p.size(); k++) {
		if (i % p[k] == 0) {
			i = i / p[k];
			k--;
		}
		if (i == 1)
			return true;
	}
	return false;
}

int ugly(int n)
{
	int index = 6;
	for (int i = 6; i <= INF; i++) {
		if (isugly(i) == true) {
			uglylist[index] = i;
			index++;
		}
		if (index > n) break;
	}
	return uglylist[n];
}


int main(void)
{
	int n; cin >> n;
	uglylist[1] = 1;
	uglylist[2] = 2;
	uglylist[3] = 3;
	uglylist[4] = 4;
	uglylist[5] = 5;

	cout << ugly(n);

	cout << endl;
	for (int i = 1;i <= n; i++) {
		cout<< uglylist[i] << " ";
	}
	return 0;
}