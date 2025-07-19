#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToPostfix(string exp) {
    stack<string> st;
    for (int i = exp.size() - 1; i >= 0; --i) {
        char c = exp[i];
        if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + c;
            st.push(temp);
        } else {
            st.push(string(1, c));
        }
    }
    return st.top();
}

int main() {
    int T; cin >> T;
    cin.ignore();
    while (T--) {
        string exp;
        getline(cin, exp);
        cout << prefixToPostfix(exp) << "\n";
    }
    return 0;
}
