class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> r(m, vector<int>(n+1, 0));
        vector<vector<int>> c(m+1, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                r[i][j+1] = r[i][j] + grid[i][j];
                c[i+1][j] = c[i][j] + grid[i][j];
            }
        }

        int maxSize = min(m, n);

        for(int k=maxSize; k>=2; k--){
            for(int i=0; i+k<=m; i++){
                for(int j=0; j+k<=n; j++){
                    int target = r[i][j + k] - r[i][j];
                    bool flag = true;

                    for(int x=i; x<i+k; x++){
                        if(r[x][j + k] - r[x][j] != target){
                            flag = false;
                            break;
                        }
                    }

                    for(int y=j; y<j+k && flag; y++){
                        if(c[i + k][y] - c[i][y] != target){
                            flag = false;
                            break;
                        }
                    }

                    int d1 = 0, d2 = 0;
                    for(int t=0; t<k; t++){
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if(flag && d1 == target && d2 == target)
                        return k;
                }
            }
        }

        return 1;
    }
};