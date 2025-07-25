#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> board;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q')
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

bool solve(int row) {
    if (row == N)
        return true;
    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            if (solve(row + 1))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    cin >> N;
    board = vector<string>(N, string(N, '.'));
    if (solve(0)) {
        for (int i = 0; i < N; ++i)
            cout << board[i] << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
