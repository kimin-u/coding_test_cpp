#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INTMAX 100001
using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<int> visit;
int timee = INTMAX;


void bfs(void) {
	while (!pq.empty()) {
		int tmpi = pq.top().second;
		int tmptime = pq.top().first;
		pq.pop();
		visit[tmpi] = true;
		if (tmpi == k) {
			timee = tmptime;
			break;
		}

		else {
			if (tmpi * 2 >= 0 && tmpi * 2 < INTMAX && visit[tmpi * 2] == false) {
				pq.push({ tmptime , tmpi * 2 });
			}
			if (tmpi + 1 >= 0 && tmpi + 1 < INTMAX && visit[tmpi + 1] == false) {
				pq.push({  tmptime + 1,tmpi + 1 });
			}
			if (tmpi - 1 >= 0 && tmpi - 1 < INTMAX && visit[tmpi - 1] == false) {
				pq.push({  tmptime + 1, tmpi - 1 });
			}


		}
	}
}

int main(void)
{
	cin >> n >> k;
	pq.push({ 0,n });
	visit.assign(INTMAX, 0);
	visit[n] = 1;

	bfs();
	cout << timee;

	return 0;

}