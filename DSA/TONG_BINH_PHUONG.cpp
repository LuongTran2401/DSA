#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<int> dp(N + 1, INT_MAX);
        	dp[0] = 0;
        if(N==2){
        dp[N]=1;
		}
		else{
        	for (int i = 1; i <= N; ++i) {
            	for (int j = 1; j < N && j * j <= i; ++j){
                	dp[i] = min(dp[i], dp[i - j * j] + 1);
            	}
        	}
		}
        cout << dp[N] << endl;
    }
    return 0;
}
