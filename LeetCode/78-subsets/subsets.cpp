class Solution {
public:
    void findSubsets(int idx, vector<int>& nums,vector<vector<int>>& ans, vector<int>& subset){
        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        findSubsets(idx+1, nums, ans, subset);

        subset.pop_back();
        findSubsets(idx+1, nums, ans, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        findSubsets(0, nums, ans, subset);

        return ans;
    }
};