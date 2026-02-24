class Solution {
public:
    int maxSubarraySum(vector<int>& nums){
        int maxSum = nums[0];
        int bestEnding = nums[0];

        for(int i=1; i<nums.size(); i++){
            bestEnding = max(nums[i], bestEnding+nums[i]);
            maxSum = max(maxSum, bestEnding);
        }
        return maxSum;
    }
    int minSubarraySum(vector<int>& nums){
        int bestEnding = nums[0];
        int minSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            bestEnding = min(nums[i], bestEnding+nums[i]);
            minSum = min(minSum, bestEnding);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubarraySum(nums);
        int minSum = minSubarraySum(nums);

        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum == minSum)
            return maxSum;
            
        return max(maxSum, sum-minSum);
    }
};