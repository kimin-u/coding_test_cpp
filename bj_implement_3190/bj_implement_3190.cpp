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

	//��� ��ġ �Է¹ޱ� 
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		map[x][y] = 1;
	}

	int l;
	cin >> l;//���� ��ȯ Ƚ�� l

	vector<int> time; //�� �� �Ŀ�~
	vector<char> direction;  //� ��������` 

	for (int i = 0; i < l; i++) {
		int tmptime;
		char tmpd;
		cin >> tmptime >> tmpd;
		time.push_back(tmptime);
		direction.push_back(tmpd);
	}

	int resultt = 0; // ���� ����ð��� ǥ���� ���� 
	//���� ���� ���� : ���� �ε����ų� > head�� ��ǥ�� �Ǵ��Ѵ�
	//2 : �ڽ��� ���� �浹 
	//������ ��ŭ�� �迭���̤��� ���� ���͸� ������ �ִٰ� ��ȸ�ϸ� �ڽŰ��� �浹���θ� �˻�

	vector<pair<int, int>> dummy; //�ڽ��� �� �̵���θ� ������ ������
	int i = 0;
	int j = 0; //���� ���� head�� ����� i,j

	string state = "��";

	dummy.push_back(make_pair(0, 0));

	int lent = -1;
	for (int q = 0; q < time.size(); q++) {
		if (lent < time[q])
			lent = time[q];
	}

	while (true) {
		//t�� ��� �ٿ������ٰ� �ϳ��� ���϶����� event�� �˻��ϰ�
		//���̴ٰ� 0�̵Ǹ� ������ȯ���� �����Ѵ� . 
		for (int t = 0; t <= lent+n+1; t++) {
			//���ʸ����� �ൿ�� �ǹ�.

			for (int k = 0; k < time.size(); k++) {
				time[k]--;
				//cout << time[k];
				if (time[k] == -1) {
					//������ȯ�� �ؾ��� 
					if (direction[k] == 'L') { // ��ȸ��
						if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
					}
					else if (direction[k] == 'D') { // ��ȸ��
						if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
						else if (state == "��") {
							state = "��";
						}
					}
				}
				//if�� ��;;
			}
			//������ȯ���� �ʰ� ���� ������ �ϳ� �����ؾ���. 
			if (state == "��") {
				j++;
			}
			else if (state == "��") {
				j--;
			}
			else if (state == "��") {
				i--;
			}
			else if (state == "��") {
				i++;
			}
			//���ӽð� �ϳ� �����ϰ� 
			resultt++;

			//cout << endl<< resultt<<"��, ������ġ : "<< i << " " << j << " " << state << endl;
			//���� �ε����°�? Ȯ���ϱ�
			if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) goto end;

				

			//�ڽ��� ���̶� �ε������� Ȯ���ϱ� 
			for (int p = 0; p < dummy.size()-1; p++) {
				if ((i == dummy[p].first) && (j == dummy[p].second)) goto end;
			}

			dummy.push_back(make_pair(i, j));
			//����� �־��°�?
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