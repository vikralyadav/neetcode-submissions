class Solution {
public:


 void solve(vector<int>& coins, int amount, vector<vector<int>> &dp, int n){

    int INF = 1e9;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= amount; j++){

            if(j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0){
                dp[i][j] = INF;
            }
            else{
                if(coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
}
  

  int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
       solve(coins, amount, dp, n);


      if(dp[n][amount] >= 1e9) return -1;


       return dp[n][amount];
        
    }
};
