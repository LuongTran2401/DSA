#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nqueen(vector<vector<string>>& ans, vector<string>& board,
                vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal,
                int col, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[row + col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                lowerDiagonal[row + col] = 1;

                nqueen(ans, board, leftRow, upperDiagonal, lowerDiagonal, col + 1, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        nqueen(ans, board, leftRow, upperDiagonal, lowerDiagonal, 0, n);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    if (solutions.empty()) {
        cout << -1 << endl;
    } else {
        for (const string& row : solutions[0]) {
            cout << row << '\n';
        }
    }

    return 0;
}