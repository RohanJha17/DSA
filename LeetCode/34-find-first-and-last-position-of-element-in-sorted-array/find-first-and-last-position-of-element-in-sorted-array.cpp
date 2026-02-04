class Solution {
public:
    int findFirstIdx(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;

        int first = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else{
                first = mid;
                high = mid-1;
            }
        }

        return first;
    }
    int findSecondIdx(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;

        int second = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else{
                second = mid;
                low =  mid+1;
            }
        }

        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstIdx(nums, target);
        int second = findSecondIdx(nums, target);

        return {first, second};
    }
};