#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

vector<int> dijkstra(int start, int N, const vector<vector<pii>>& adj) {
    vector<int> dist(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<pii>> adj(N);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int src, dest;
            cin >> src >> dest;
            vector<int> dist = dijkstra(src, N, adj);
            if (dist[dest] == INF)
                cout << -1 << endl;
            else
                cout << dist[dest] << endl;
        }
    }
    return 0;
}
