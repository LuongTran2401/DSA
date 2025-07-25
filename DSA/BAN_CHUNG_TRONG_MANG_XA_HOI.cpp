#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<set<int>> friends(N);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            friends[u].insert(v);
            friends[v].insert(u);
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int a, b;
            cin >> a >> b;

            if (a == b) {
                cout << friends[a].size() << endl;
            } else {
                int common = 0;
                for (int f : friends[a]) {
                    if (friends[b].count(f)) {
                        common++;
                    }
                }
                cout << common << endl;
            }
        }
    }

    return 0;
}
