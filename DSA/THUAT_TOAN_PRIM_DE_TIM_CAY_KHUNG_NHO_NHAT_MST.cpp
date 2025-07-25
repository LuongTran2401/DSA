#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1005;
const int INF = 1e9;

vector<pair<int, int>> adj[MAX];
bool visited[MAX];

int prim(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int total_cost = 0;
    int count = 0; 
    pq.push({0, 1});
    while (!pq.empty() && count < n) {
        pair<int, int> top = pq.top(); pq.pop();
        int w = top.first;
        int u = top.second;
        if (visited[u]) continue;
        visited[u] = true;
        total_cost += w;
        count++;
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    return total_cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) adj[i].clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
        cout << prim(N) << endl;
    }
    return 0;
}
