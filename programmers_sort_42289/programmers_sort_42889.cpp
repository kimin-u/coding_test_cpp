//2019 KAKAO BLIND RECRUITMENT
//https://school.programmers.co.kr/learn/courses/30/lessons/42889
//���Ĺ���/�ſ� �������ε� sort method ���������� ������


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, double> a, pair<int, double> b) {
    if (a.second > b.second) return true;
    if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> result(N);
    vector<pair<int, double>> answer(N);
    int stagelen = stages.size();
    double tmp;
    for (int i = 0; i < N; i++) {
        //i = stage���� �������� �����Ұž� 
        int noclearcnt = 0;
        int playedcnt = 0;
        for (int j = 0; j < stagelen; j++) {
            if (stages[j] > i + 1)
                playedcnt++;
            if (stages[j] == i + 1) {
                playedcnt++;
                noclearcnt++;
            }
        }
        if (playedcnt != 0)
            tmp = (double)(noclearcnt) / playedcnt;
        else
            tmp = 0;
        answer[i] = make_pair(i + 1, tmp);
    }
    //�������� ����

    sort(answer.begin(), answer.end(), cmp);

    for (int i = 0; i < N; i++) {
        result[i] = answer[i].first;
    }
    //result�� ���� �ű��
    return result;
}
