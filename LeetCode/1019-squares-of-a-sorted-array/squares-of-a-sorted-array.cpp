class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = 0, j = n-1;
        int pos = n-1;
        while(i <= j){
            long long leftSq = 1LL * nums[i] * nums[i];
            long long rightSq =  1LL * nums[j] * nums[j];

            if(leftSq > rightSq){
                ans[pos] = leftSq;
                i++;
            }else{
                ans[pos] = rightSq;
                j--;
            }
            pos--;
        }

        return ans;
    }
};