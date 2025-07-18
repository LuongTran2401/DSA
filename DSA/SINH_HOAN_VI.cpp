#include<bits/stdc++.h>

using namespace std;

int N;

void hoanvi(int N){
	vector<int> v;
	for(int i=1;i<=N;i++){
	v.push_back(i);
	}
	do{
		for(auto i:v) cout <<i;
		cout<<" ";
	}
	while (next_permutation(v.begin(),v.end()));
	cout<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>N;
		hoanvi(N);
	}
	return 0;
}