#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        vector<int> dp(K + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= K; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i >= A[j]) {
                    dp[i] = (dp[i] + dp[i - A[j]]) % MOD;
                }
            }
        }
        cout << dp[K] << endl;
    }
    return 0;
}
