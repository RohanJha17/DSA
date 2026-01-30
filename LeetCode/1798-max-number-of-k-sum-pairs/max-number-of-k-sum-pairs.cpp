class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size() == 0) 
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ops = 0;
        int i = 0, j = nums.size()-1;
        while(i < j){
            if(nums[i]+nums[j] > k)
                j--;
            else if(nums[i]+nums[j] < k)
                i++;
            else{
                ops++;
                i++; j--;
            }
        }

        return ops;
    }
};