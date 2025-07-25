#include <iostream>
#include <vector>
using namespace std;

const int MAX = 105;
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    if (!t) {
        cout << -1 << endl;
        return 0;
    }
    while (t--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) adj[i].clear();
        fill(visited, visited + N, false);

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (M != N - 1) {
            cout << "NO" << endl;
            continue;
        }
        bool hasCycle = dfs(0, -1);
        bool isConnected = true;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                isConnected = false;
                break;
            }
        }
        if (!hasCycle && isConnected)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
