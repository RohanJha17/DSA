class Solution {
public:
    int findResSum(vector<int>& nums, int div){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)div);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = *max_element(nums.begin(), nums.end());

        int low = 1, high = n;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(findResSum(nums, mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};