#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        memset(visited, false, sizeof(visited));
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        BFS(s);
        cout << dist[t] << endl;
    }
    return 0;
}
