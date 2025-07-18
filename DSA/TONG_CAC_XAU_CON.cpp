#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long sumSubstrings(string s) {
    int n = s.length();
    vector<long long> sum(n);
    sum[0] = s[0] - '0';
    long long res = sum[0];
    for (int i = 1; i < n; ++i) {
        int num = s[i] - '0';
        sum[i] = (sum[i - 1] * 10 + 1LL * (i + 1) * num) % MOD;
        res = (res + sum[i]) % MOD;
    }
    return res;
}

int main() {
    int T;
	cin >> T;
    while (T--) {
        string N;
        cin >> N;
        cout << sumSubstrings(N) << '\n';
    }
    return 0;
}
