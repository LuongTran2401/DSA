#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
	cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> A[i][j];
        vector<vector<int>> dp(N, vector<int>(M, 0));
        dp[0][0] = A[0][0];
        for (int j = 1; j < M; ++j)
            dp[0][j] = dp[0][j - 1] + A[0][j];
        for (int i = 1; i < N; ++i)
            dp[i][0] = dp[i - 1][0] + A[i][0];
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                dp[i][j] = A[i][j] + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        cout << dp[N - 1][M - 1] << endl;
    }
    return 0;
}
