class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return;
        k = k%n;
        if(k == 0)
            return;
        
        reverse(nums.begin(), nums.end());

        int l = 0, r = k-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        int left = k, right = n-1;
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};