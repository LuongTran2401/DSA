#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs_min_hops(int N, vector<vector<int>>& adj, int S, int T) {
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;
    q.push({S, 0});
    visited[S] = true;
    while (!q.empty()) {
        auto [u, hops] = q.front(); q.pop();
        if (u == T) return hops;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, hops + 1});
            }
        }
    }
    return -1;
}

int dijkstra_min_latency(int N, vector<vector<pair<int, int>>>& adj, int S, int T) {
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top(); pq.pop();
        if (u == T) return cur_dist;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > cur_dist + w) {
                dist[v] = cur_dist + w;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;
        vector<vector<int>> adj_hops(N);
        vector<vector<pair<int, int>>> adj_latency(N);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj_hops[u].push_back(v);
            adj_hops[v].push_back(u);

            adj_latency[u].push_back({v, w});
            adj_latency[v].push_back({u, w});
        }
        int min_hops = bfs_min_hops(N, adj_hops, S, T);
        int min_latency = dijkstra_min_latency(N, adj_latency, S, T);
        cout << min_hops << endl;
        cout << min_latency << endl;
    }

    return 0;
}
