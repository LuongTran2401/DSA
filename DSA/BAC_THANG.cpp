#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k, mod = 1e9 + 7;
        cin >> n >> k;
        long long a[n] = {}, b[n];
        for (int i = 0; i < min(n, k); i++)
            a[i] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++){
            if (i <= k)
                a[i] = (a[i] + b[i - 1]) % mod;
            else{
                long long m = (b[i - 1] - b[i - k - 1]) % mod;
                if (m < 0)
                    m += mod;
                a[i] = (a[i] + m) % mod;
            }
            b[i] = (b[i - 1] + a[i]) % mod;
        }
        cout << a[n - 1] << endl;
    }
}