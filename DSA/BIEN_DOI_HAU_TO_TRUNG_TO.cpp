#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToInfix(string exp) {
    stack<string> st;
    for (char c : exp) {
        if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string tmp = "(" + op1 + c + op2 + ")";
            st.push(tmp);
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
        cout << postfixToInfix(exp) << "\n";
    }
    return 0;
}
