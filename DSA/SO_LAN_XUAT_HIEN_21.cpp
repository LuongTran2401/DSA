#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> freq;
        vector<int> A(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            freq[A[i]]++;
        }

        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), cmp);

        for (auto p : v) {
            for (int i = 0; i < p.second; ++i) {
                cout << p.first << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
