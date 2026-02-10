class Solution {
public:
    bool isPossible(vector<int>& nums, int day, int m, int k){
        int count = 0, noOfB = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= day){
                count++;
            }
            else{
                noOfB += count/k;
                count = 0;
            }
        }
        noOfB += count/k;
        if(noOfB >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k)
            return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isPossible(bloomDay, mid, m, k))
                high = mid-1;
            else
                low = mid+1;
        }

        return low;
    }
};