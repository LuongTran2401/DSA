#include<bits/stdc++.h>
using namespace std;
vector<int > a[1001];
bool vs[1001];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(q.size()>0)
    {
        int top=q.front();q.pop();
        cout<<top<<' ';
        vs[top]=true;
        for(int i=0;i<a[top].size();i++)
            if(vs[a[top][i]]==false)
            {
                vs[a[top][i]]=true;
                q.push(a[top][i]);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        for(int i=0;i<1001;i++)
            a[i].clear();
        int canh,start,n;
        cin>>n>>canh>>start;
        memset(vs,false,sizeof(vs));
        while(canh--)
        {
            int c,b;cin>>b>>c;
            a[c].push_back(b);
            a[b].push_back(c);
        }
        BFS(start);
        cout<<endl;
    }
}