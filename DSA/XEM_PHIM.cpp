#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; 
	cin >> T;
    while (T--) {
        int C, N;
        cin >> C >> N;
        vector<int> w(N);
        for (int i = 0; i < N; ++i)
            cin >> w[i];

        vector<int> dp(C + 1, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = C; j >= w[i]; --j) {
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
            }
        }
        cout << dp[C] << '\n';
    }
    return 0;
}
