#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> adj(N);
        vector<int> in_degree(N, 0);

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            in_degree[v]++;
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int completed;
            cin >> completed;

            int count = 0;
            for (int v : adj[completed]) {
                if (in_degree[v] == 1) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
