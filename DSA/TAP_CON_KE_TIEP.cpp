#include<bits/stdc++.h>

using namespace std;

void nextCombination(int N, int K, vector<int>& X) {
    int i = K - 1;
    while (i >= 0 && X[i] == N - K + i + 1) {
        i--;
    }
    if (i >= 0) {
        X[i]++;
        for (int j = i + 1; j < K; j++) {
            X[j] = X[j - 1] + 1;
        }
    } else {
        for (int i = 0; i < K; i++) {
            X[i] = i + 1;
        }
    }
    for (int i = 0; i < K; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}

int main(){
	int test;
	cin>>test;
	for (int i=0;i<test;i++){
	int N,K;
	cin>>N>>K;
	vector<int> X(K);
        for (int j = 0; j < K; j++) {
            cin >> X[j];
        }
        nextCombination(N, K, X);
    }	
	return 0;
}