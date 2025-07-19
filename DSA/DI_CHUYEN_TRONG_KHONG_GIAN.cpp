#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 0, 0, 1, -1};  
int dy[] = {-1, 1, 0, 0, 0, 0};  
int dz[] = {0, 0, -1, 1, 0, 0};  

int bfs(vector<vector<vector<char>>> &box, int A, int B, int C, int sx, int sy, int sz) {
    queue<tuple<int, int, int, int>> q;  
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));

    q.push({sx, sy, sz, 0});
    visited[sx][sy][sz] = true;

    while (!q.empty()) {
        auto [x, y, z, steps] = q.front(); q.pop();

        if (box[x][y][z] == 'E') return steps;

        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];

            if (nx >= 0 && nx < A && ny >= 0 && ny < B && nz >= 0 && nz < C
                && box[nx][ny][nz] != '#' && !visited[nx][ny][nz]) {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        vector<vector<vector<char>>> box(A, vector<vector<char>>(B, vector<char>(C)));

        int sx = -1, sy = -1, sz = -1;

        string line;
        getline(cin, line);

        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                getline(cin, line);
                for (int k = 0; k < C; ++k) {
                    box[i][j][k] = line[k];
                    if (line[k] == 'S') {
                        sx = i; sy = j; sz = k;
                    }
                }
            }
            getline(cin, line); 
        }

        cout << bfs(box, A, B, C, sx, sy, sz) << "\n";
    }

    return 0;
}
