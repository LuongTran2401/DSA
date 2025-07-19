#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getMaxArea(vector<ll>& heights) {
    int n = heights.size();
    stack<int> st;
    ll max_area = 0;
    int i = 0;

    while (i < n) {
        if (st.empty() || heights[st.top()] <= heights[i]) {
            st.push(i++);
        } else {
            int top = st.top(); st.pop();
            ll width = st.empty() ? i : i - st.top() - 1;
            ll area = heights[top] * width;
            max_area = max(max_area, area);
        }
    }

    while (!st.empty()) {
        int top = st.top(); st.pop();
        ll width = st.empty() ? i : i - st.top() - 1;
        ll area = heights[top] * width;
        max_area = max(max_area, area);
    }

    return max_area;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<ll> H(N);
        for (int i = 0; i < N; ++i) cin >> H[i];
        cout << getMaxArea(H) << "\n";
    }
    return 0;
}
