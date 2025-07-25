#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, numLines, Q;
        cin >> N >> numLines >> Q;
        vector<vector<int>> station_to_lines(N);
        vector<vector<int>> lines(numLines);
        for (int i = 0; i < numLines; ++i) {
            int k;
            cin >> k;
            lines[i].resize(k);
            for (int j = 0; j < k; ++j) {
                int station;
                cin >> station;
                lines[i][j] = station;
                station_to_lines[station].push_back(i);
            }
        }
        while (Q--) {
            int src, dst;
            cin >> src >> dst;

            if (src == dst) {
                cout << 0 << "\n";
                continue;
            }
            unordered_map<int, unordered_set<int>> visited;
            queue<tuple<int, int, int>> q;
            for (int line : station_to_lines[src]) {
                q.emplace(src, line, 0);
                visited[src].insert(line);
            }

            int result = -1;

            while (!q.empty()) {
                auto [station, line, changes] = q.front();
                q.pop();
                for (int next_station : lines[line]) {
                    if (next_station == dst) {
                        result = changes;
                        goto done;
                    }
                    for (int next_line : station_to_lines[next_station]) {
                        if (visited[next_station].count(next_line) == 0) {
                            visited[next_station].insert(next_line);
                            int new_changes = (next_line == line) ? changes : changes + 1;
                            q.emplace(next_station, next_line, new_changes);
                        }
                    }
                }
            }
        done:
            cout << result << "\n";
        }
    }
    return 0;
}
