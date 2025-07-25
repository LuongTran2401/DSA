#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};
const int MAX = 1005;
int parent[MAX];

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

bool union_set(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    parent[pu] = pv;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<Edge> edges;
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        for (int i = 0; i < N; ++i) parent[i] = i;
        sort(edges.begin(), edges.end());
        int mst_cost = 0;
        int edge_count = 0;
        for (Edge e : edges) {
            if (union_set(e.u, e.v)) {
                mst_cost += e.w;
                edge_count++;
                if (edge_count == N - 1) break;
            }
        }
        if (edge_count == N - 1) cout << mst_cost << endl;
        else cout << -1 << endl;
    }
    return 0;
}
