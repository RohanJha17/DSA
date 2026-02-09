class Solution {
public:
    long long findMinSum(vector<int>& nums, int mid){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = *max_element(piles.begin(), piles.end());

        int low = 1, high = n;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(findMinSum(piles, mid) <= h){
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return low;
    }
};