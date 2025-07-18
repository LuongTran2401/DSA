#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1001;

long long fac[MAX], inv[MAX];

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;

    inv[MAX - 1] = powmod(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

long long C(int n, int k) {
    if (k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << C(n, k) << '\n';
    }
    return 0;
}
