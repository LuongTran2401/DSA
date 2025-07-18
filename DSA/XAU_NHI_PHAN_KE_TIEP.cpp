#include<bits/stdc++.h>

using namespace std;

void nextBinaryString(string &s){
    int n = s.length();
    int i = n - 1;
    while (i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if (i >= 0){
        s[i] = '1';
    }
}

bool isBinaryString(const string &s){
    for (char c : s){
        if (c != '0' && c != '1') return false;
    }
    return true;
}

int main(){
    int test;
    cin >> test;
    string s;
    getline(cin, s);
    while (test--){
        string X;
        getline(cin, X);
        if (!isBinaryString(X)){
            cout << "chuoi khong hop le" << endl;
            continue;
        }
        nextBinaryString(X);
        cout << X << endl;
    }
    return 0;
}