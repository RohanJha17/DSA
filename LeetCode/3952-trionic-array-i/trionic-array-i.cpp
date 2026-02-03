class Solution {
public:
    bool isStrictlyInc(vector<int>& nums, int st, int end){
        for(int i=st; i<end; i++){
            if(nums[i] >= nums[i+1])
                return false;
        }
        return true;
    }
    bool isStrictlyDec(vector<int>& nums, int st, int end){
        for(int i=st; i<end; i++){
            if(nums[i] <= nums[i+1])
                return false;
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;

        for(int p=1; p<n-2; p++){
            if(!isStrictlyInc(nums, 0, p))
                continue;
                
            for(int q=p+1; q<n-1; q++){
                if(isStrictlyDec(nums, p, q) && isStrictlyInc(nums, q, n-1))
                    return true;
            }
        }

        return false;
    }
};