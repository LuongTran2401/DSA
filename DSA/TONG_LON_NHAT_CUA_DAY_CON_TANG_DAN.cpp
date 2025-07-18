#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int> &A) {
    int n = A.size();
    vector<int> dp = A;
    int res = A[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        cout << maxSumIncreasingSubsequence(A) << '\n';
    }
    return 0;
}
