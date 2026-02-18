class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0;
        int minLen = INT_MAX;

        int sum = 0;
        while(high < nums.size()){
            sum += nums[high];

            while(sum >= target){
                int len = high-low+1;
                minLen = min(minLen, len);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};