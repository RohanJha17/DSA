class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int zero = 0, one = 0, maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zero++;
            else
                one++;

            int diff = zero - one;
            if(diff == 0){
                maxLen = max(maxLen, i+1);
                continue;
            }

            if(m.find(diff) == m.end())
                m[diff] = i;
            else
                maxLen = max(maxLen, i-m[diff]);
        }

        return maxLen;
    }
};