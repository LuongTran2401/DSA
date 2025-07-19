#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> C(n + m);
        
        for (int i = 0; i < n; ++i) {
            cin >> C[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> C[n + i];
        }
        
        sort(C.begin(), C.end());
        
        for (int x : C) cout << x << " ";
        cout << '\n';
    }
    return 0;
}
