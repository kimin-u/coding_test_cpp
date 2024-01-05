#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	int n, k;
	cin >> n;
	cin >> k;
	vector<vector<int>> map(n, vector<int>(n, 0));

	//사과 위치 입력받기 
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		map[x][y] = 1;
	}

	int l;
	cin >> l;//방향 변환 횟수 l

	vector<int> time; //몇 초 후에~
	vector<char> direction;  //어떤 방향으로` 

	for (int i = 0; i < l; i++) {
		int tmptime;
		char tmpd;
		cin >> tmptime >> tmpd;
		time.push_back(tmptime);
		direction.push_back(tmpd);
	}

	int resultt = 0; // 게임 종료시간을 표현할 변수 
	//게임 종료 조건 : 벽에 부딪히거나 > head의 좌표로 판단한다
	//2 : 자신의 몸과 충돌 
	//몸길이 만큼의 배열길이ㄹ를 갖는 벡터를 가지고 있다가 순회하며 자신과의 충돌여부를 검색

	vector<pair<int, int>> dummy; //자신의 몸 이동경로를 저장할 벡터임
	int i = 0;
	int j = 0; //현재 뱀의 head를 담당할 i,j

	string state = "우";

	dummy.push_back(make_pair(0, 0));

	int lent = -1;
	for (int q = 0; q < time.size(); q++) {
		if (lent < time[q])
			lent = time[q];
	}

	while (true) {
		//t를 계속 줄여나가다가 하나씩 줄일때마다 event를 검사하고
		//줄이다가 0이되면 방향전환등을 진행한다 . 
		for (int t = 0; t <= lent+n+1; t++) {
			//매초마다의 행동을 의미.

			for (int k = 0; k < time.size(); k++) {
				time[k]--;
				//cout << time[k];
				if (time[k] == -1) {
					//방향전환을 해야함 
					if (direction[k] == 'L') { // 좌회전
						if (state == "우") {
							state = "상";
						}
						else if (state == "좌") {
							state = "하";
						}
						else if (state == "상") {
							state = "좌";
						}
						else if (state == "하") {
							state = "우";
						}
					}
					else if (direction[k] == 'D') { // 우회전
						if (state == "우") {
							state = "하";
						}
						else if (state == "좌") {
							state = "상";
						}
						else if (state == "상") {
							state = "우";
						}
						else if (state == "하") {
							state = "좌";
						}
					}
				}
				//if절 끝;;
			}
			//방향전환하지 않고 현재 방향대로 하나 증가해야함. 
			if (state == "우") {
				j++;
			}
			else if (state == "좌") {
				j--;
			}
			else if (state == "상") {
				i--;
			}
			else if (state == "하") {
				i++;
			}
			//게임시간 하나 증가하고 
			resultt++;

			//cout << endl<< resultt<<"초, 현재위치 : "<< i << " " << j << " " << state << endl;
			//벽에 부딪혔는가? 확인하기
			if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) goto end;

				

			//자신의 몸이랑 부딪혔는지 확인하기 
			for (int p = 0; p < dummy.size()-1; p++) {
				if ((i == dummy[p].first) && (j == dummy[p].second)) goto end;
			}

			dummy.push_back(make_pair(i, j));
			//사과가 있었는가?
			if (map[i][j] !=1){
				dummy.erase(dummy.begin());
			}
			/*for (int m = 0; m < dummy.size(); m++) {
				cout << dummy[m].first << ", " << dummy[m].second << "/ ";
			}
			*/
		}
	}

end:
	cout << resultt;
	return 0;



}