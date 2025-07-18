#include <bits/stdc++.h>
using namespace std;

int longestChain(vector<pair<int, int>> &pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end());
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[j].second < pairs[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
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
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        cout << longestChain(pairs) << '\n';
    }
    return 0;
}
