class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return false;

        vector<int> pre_min(n);
        pre_min[0] = nums[0];
        for(int i=1; i<n; i++){
            pre_min[i] = min(pre_min[i-1], nums[i]);
        }

        vector<int> suf_max(n);
        suf_max[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf_max[i] = max(suf_max[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            if(pre_min[i-1] < nums[i] && nums[i] < suf_max[i+1])
                return true;
        }

        return false;
    }
};