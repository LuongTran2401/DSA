#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, U, V;
        cin >> N >> M >> U >> V;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(N + 1, false);
        dfs(U, adj, visited);
        if (visited[V])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
