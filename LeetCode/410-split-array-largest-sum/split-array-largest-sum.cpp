class Solution {
public:
    int isValid(vector<int>& nums, int mid){
        int subarray = 1, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]+sum <= mid)
                sum += nums[i];
            else{
                subarray++;
                sum = nums[i];
            }
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isValid(nums, mid) <= k)
                high = mid-1;
            else
                low = mid+1;
        }

        return low;
    }
};