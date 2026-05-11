class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

    
        if (i < 0 || j < 0 || i >= n || j >= m || 
            grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

       
        dfs(grid, i + 1, j, visited); 
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited); 
    }

    int numIslands(vector<vector<char>>& grid) {


        int n = grid.size();
        int m = grid[0].size();



         vector<vector<bool>> visited(n, vector<bool>(m, false));



          int islands = 0;



          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){


                     dfs(grid, i, j, visited);
                    islands++;
                }
            }
          }


           return islands;
        
    }
};
