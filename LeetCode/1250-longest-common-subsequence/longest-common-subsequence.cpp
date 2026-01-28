class Solution {
public:
    int fun(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = 1 + fun(s, t, i-1, j-1, dp);
        
        return dp[i][j] = max(fun(s, t, i-1, j, dp), fun(s, t, i, j-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return fun(text1, text2, n-1, m-1, dp);
    }
};