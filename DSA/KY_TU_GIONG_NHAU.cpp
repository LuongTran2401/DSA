#include <bits/stdc++.h>
using namespace std;

int solve(int N, int X, int Y, int Z) {
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    dp[1] = X;
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + X;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + Z);
        } else {
            dp[i] = min(dp[i], dp[(i - 1) / 2] + Z + X);
        }
    }
    return dp[N];
}

int main() {
    int T; 
	cin >> T;
    while (T--) {
        int N, X, Y, Z;
        cin >> N >> X >> Y >> Z;
        cout << solve(N, X, Y, Z) << '\n';
    }
    return 0;
}
