class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int m, int col){
        int maxVal = -1, idx = -1;
        for(int i=0; i<m; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            int maxRowIdx = findMaxIndex(mat, m, mid);
            int left = mid-1 >= 0 ? mat[maxRowIdx][mid-1] : -1;
            int right = mid+1 < n ? mat[maxRowIdx][mid+1] : -1;

            if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right)
                return {maxRowIdx, mid};
            else if(mat[maxRowIdx][mid] < left)
                high = mid-1;
            else
                low = mid+1;
        }

        return {-1, -1};
    }
};