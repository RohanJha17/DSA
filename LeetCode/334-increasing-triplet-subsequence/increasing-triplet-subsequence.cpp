class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return false;

        vector<int> p_min(n);
        p_min[0] = nums[0];
        for(int i=1; i<n; i++){
            p_min[i] = min(p_min[i-1], nums[i]);
        }

        vector<int> s_max(n);
        s_max[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            s_max[i] = max(s_max[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            if(p_min[i-1] < nums[i] && nums[i] < s_max[i])
                return true;
        }

        return false;
    }
};