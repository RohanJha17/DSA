class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size());
        int ans = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            LIS[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j]+1);
            }
            ans = max(ans, LIS[i]);
        }

        return ans;
    }
};