class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = nums[0], maxSum = nums[0], minSum = nums[0];
        int bestEndingMax = nums[0], bestEndingMin = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];

            bestEndingMax = max(nums[i], nums[i]+bestEndingMax);
            maxSum = max(maxSum, bestEndingMax);

            bestEndingMin = min(nums[i], nums[i]+bestEndingMin);
            minSum = min(minSum, bestEndingMin);
        }
        if(sum == minSum)
            return maxSum;

        return max(maxSum, sum-minSum);
    }
};