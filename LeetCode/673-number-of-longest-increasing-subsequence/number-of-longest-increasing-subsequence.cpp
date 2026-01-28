class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> lis(n, 1), count(n, 1);
        int maxLen = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j]+1;
                        count[i] = count[j];
                    }
                    else if(lis[j]+1 == lis[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, lis[i]);
        }     

        int ans = 0;
        for(int i=0; i<n; i++){
            if(lis[i] ==  maxLen)
                ans += count[i];
        }

        return ans;
    }
};