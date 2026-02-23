class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0], oneDelete = INT_MIN;
        int maxSum = arr[0];

        for(int i=1;i<arr.size(); i++){
            int prevnoDelete = noDelete;

            noDelete = max(noDelete+arr[i], arr[i]);
            int val;
            if(oneDelete == INT_MIN)
                val = arr[i];
            else
                val = oneDelete + arr[i]; 

            oneDelete = max(val, prevnoDelete);

            maxSum = max(maxSum, max(noDelete, oneDelete));
        }  

        return maxSum;
    }
};