#include <iostream>
#include <vector>
using namespace std;

const int N = 3;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == '.' && !visited[x][y];
}

bool dfs(int x, int y, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    if (x == 2 && y == 2) return true;

    visited[x][y] = true;

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny, maze, visited)) {
            if (dfs(nx, ny, maze, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> maze(3, vector<char>(3));
        vector<vector<bool>> visited(3, vector<bool>(3, false));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> maze[i][j];

        if (dfs(0, 0, maze, visited))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
