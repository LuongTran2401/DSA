#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1000 + 5;

long long fac[MAX], inv_fac[MAX];

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b % 2)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void prepare() {
    fac[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fac[i] = fac[i - 1] * i % MOD;

    inv_fac[MAX - 1] = powmod(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}

int main() {
    prepare();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k > n)
            cout << 0 << endl;
        else {
            long long res = fac[n] * inv_fac[n - k] % MOD;
            cout << res << endl;
        }
    }
    return 0;
}
