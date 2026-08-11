class Solution {
public:

 bool solve(int i, int j,
           vector<vector<char>>& board,
           string word,
           vector<vector<bool>>& visited,
           int index) {

    // All characters matched
    if (index == word.size()) {
        return true;
    }

    int n = board.size();
    int m = board[0].size();

    // Out of bounds
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }

    // Already visited or character doesn't match
    if (visited[i][j] || board[i][j] != word[index]) {
        return false;
    }

    // Mark current cell
    visited[i][j] = true;

    bool found =
        solve(i - 1, j, board, word, visited, index + 1) ||
        solve(i + 1, j, board, word, visited, index + 1) ||
        solve(i, j - 1, board, word, visited, index + 1) ||
        solve(i, j + 1, board, word, visited, index + 1);

    // Backtrack
    visited[i][j] = false;

    return found;
}


bool exist(vector<vector<char>>& board, string word) {

    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (board[i][j] == word[0]) {

                if (solve(i, j, board, word, visited, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
        
    }
};
