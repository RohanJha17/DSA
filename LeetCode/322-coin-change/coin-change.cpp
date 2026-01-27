class Solution {
public:
    int minCoins(vector<int>&coins, int amount, int idx, vector<vector<int>>& dp){
        if(amount == 0)
            return 0;
        if(idx >= coins.size())
            return 1e9;

        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int pick = 1e9;
        if(amount - coins[idx] >= 0)
            pick = 1 + minCoins(coins, amount-coins[idx], idx, dp);
        
        int notPick = minCoins(coins, amount, idx+1, dp);

        return dp[idx][amount] =  min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int ans = minCoins(coins, amount, 0, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};