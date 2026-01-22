class Solution {
public:
    int isFind(int i, int j, int m, int n, vector<vector<int>>& ans){
        if(i == m-1 && j == n-1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        
        if(ans[i][j] != -1)
            return ans[i][j];

        int right = isFind(i, j+1, m, n, ans);
        int down = isFind(i+1, j, m, n, ans);

        return ans[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        return isFind(0, 0, m, n, ans);
    }
};