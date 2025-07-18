#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<long long> prev(K + 1, 0), cur(K + 1, 0);
        for (int d = 1; d <= 9 && d <= K; ++d) {
            prev[d] = 1;
        }
        for (int len = 2; len <= N; ++len) {
            fill(cur.begin(), cur.end(), 0);

            for (int sum = 0; sum <= K; ++sum) {
                for (int d = 0; d <= 9; ++d) {
                    if (sum >= d)
                        cur[sum] = (cur[sum] + prev[sum - d]) % MOD;
                }
            }
            swap(cur, prev);
        }
        cout << prev[K] << endl;
    }
    return 0;
}
