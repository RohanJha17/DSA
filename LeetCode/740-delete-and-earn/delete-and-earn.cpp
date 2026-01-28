class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        int x = *max_element(nums.begin(), nums.end());

        vector<int> sum(x+1, 0);
        for(int val : nums){
            sum[val] += val;
        }
        
        int prev2 = sum[0];
        int prev1 = max(sum[0], sum[1]);

        for(int i=2; i<=x; i++){
            int curr = max(sum[i]+prev2, 0+prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};