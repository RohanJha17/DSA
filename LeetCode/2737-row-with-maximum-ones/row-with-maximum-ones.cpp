class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxCount = 0, idx = 0;
        for(int i=0; i<m; i++){
            int countOne = 0;
            for(int j=0; j<n; j++){
                countOne += mat[i][j];
            }

            if(countOne > maxCount){
                maxCount = countOne;
                idx = i;
            }
        }

        return {idx, maxCount};
    }
};