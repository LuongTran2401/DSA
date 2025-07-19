#include <bits/stdc++.h>
using namespace std;

int idx; 
int depth(string &s, int d) {
    if (idx >= s.size()) return d - 1;
    if (s[idx] == 'l') {
        idx++;
        return d;
    }

    idx++;
    int left = depth(s, d + 1);  
    int right = depth(s, d + 1);
    return max(left, right);     
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int len;
        cin >> len;
        string s;
        cin >> s;
        idx = 0;
        cout << depth(s, 0) << endl;
    }
    return 0;
}
