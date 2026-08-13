class Solution {
public:

  bool solveBoard(vector<vector<char>>& board, string word, int i, int j, int index){

    if (index == word.size()) {
        return true;
    }

    int n = board.size();
    int m = board[0].size();

    // Out of bounds
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }

    // Current character doesn't match
    if (board[i][j] != word[index]) {
        return false;
    }

    // Mark current cell as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore 4 directions
    bool found =
        solveBoard(board, word, i + 1, j, index + 1) || // down
        solveBoard(board, word, i - 1, j, index + 1) || // up
        solveBoard(board, word, i, j + 1, index + 1) || // right
        solveBoard(board, word, i, j - 1, index + 1);    // left

    // Backtrack
    board[i][j] = temp;

    return found;

  }




    bool exist(vector<vector<char>>& board, string word) {


        int n = board.size();
        int m = board[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]==word[0]){
                  return  solveBoard(board, word, i, j, 0);

                }


               

            }
        }
        return false;  
    }
};
