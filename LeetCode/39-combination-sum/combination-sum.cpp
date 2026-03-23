class Solution {
public:
    void helper(vector<int>& a, int target, int n, int idx, vector<int>& temp, int sum, vector<vector<int>>& ans){
        if(idx == n){
            if(sum == target)
                ans.push_back(temp);
            return;
        }

        helper(a, target, n, idx+1, temp, sum, ans);
        if(a[idx]+sum <= target){
            temp.push_back(a[idx]);
            sum += a[idx];
            
            helper(a, target, n, idx, temp, sum, ans);

            temp.pop_back();
            sum -= a[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(candidates, target, candidates.size(), 0, temp, 0, ans);

        return ans;
    }
};