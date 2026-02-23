class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minEnd = nums[0], maxEnd = nums[0], maxProduct = nums[0];

        for(int i=1; i<nums.size(); i++){
            int val1 = minEnd*nums[i];
            int val2 = maxEnd*nums[i];

            minEnd = min(nums[i], min(val1, val2));
            maxEnd = max(nums[i], max(val1, val2));

            maxProduct = max(maxProduct, max(minEnd, maxEnd));
        }

        return maxProduct;
    }
};