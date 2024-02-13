#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
    cin >> n;

    vector<int> mindp(3, 0);
    vector<int> maxdp(3, 0);

    // 3xn 크기의 그래프가 있음
   // vector<vector<int>> graph(n, vector<int>(3, 0));

    int input1, input2, input3;

    for (int i = 0; i < n; i++) {
        cin >> input1 >> input2 >> input3;

        if (i == 0) {
            mindp[0] = maxdp[0] = input1;
            mindp[1] = maxdp[1] = input2;
            mindp[2] = maxdp[2] = input3;
            continue;
        }

        int prev0 = mindp[0], prev1 = mindp[1], prev2 = mindp[2];
        mindp[0] = min(prev0, prev1) + input1;
        mindp[1] = min({ prev0, prev1, prev2 }) + input2;
        mindp[2] = min(prev1, prev2) + input3;

        prev0 = maxdp[0], prev1 = maxdp[1], prev2 = maxdp[2];
        maxdp[0] = max(prev0, prev1) + input1;
        maxdp[1] = max({ prev0, prev1, prev2 }) + input2;
        maxdp[2] = max(prev1, prev2) + input3;
    }


    cout << max({ maxdp[0], maxdp[1], maxdp[2] }) << " " << min({ mindp[0], mindp[1], mindp[2] });
    return 0;
}
