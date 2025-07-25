#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countWays(int N, int K, vector<int>& A) {
    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= K; ++i) {
        for (int x : A) {
            if (i >= x) {
                dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
        }
    }
    return dp[K];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << countWays(N, K, A) << endl;
    }
    return 0;
}
