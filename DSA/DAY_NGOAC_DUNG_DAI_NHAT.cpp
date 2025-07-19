#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int max_len = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.empty()) {
                max_len = max(max_len, i - st.top());
            } else {
                st.push(i);
            }
        }
    }
    return max_len;
}

int main() {
    int T; cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        cout << longestValidParentheses(s) << "\n";
    }
    return 0;
}
