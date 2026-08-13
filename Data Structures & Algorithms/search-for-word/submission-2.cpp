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

    // Already visited
    if (board[i][j] == '#') {
        return false;
    }

    // Character doesn't match
    if (board[i][j] != word[index]) {
        return false;
    }


    char temp = board[i][j];
    board[i][j] = '#';

    bool found =
        solveBoard(board, word, i + 1, j, index + 1) ||
        solveBoard(board, word, i - 1, j, index + 1) ||
        solveBoard(board, word, i, j + 1, index + 1) ||
        solveBoard(board, word, i, j - 1, index + 1);

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
