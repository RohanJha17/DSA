class Solution {
public:
    int noOfDaysReq(vector<int>& weights, int cap){
        int totalDays = 1, load = 0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > cap){
                totalDays += 1;
                load = weights[i];
            }
            else
                load += weights[i];
        }
        return totalDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(noOfDaysReq(weights, mid) <= days)
                high = mid-1;
            else
                low = mid+1;
        }

        return low;
    }
};