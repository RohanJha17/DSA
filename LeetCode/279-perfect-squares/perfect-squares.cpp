class Solution {
public:
    bool checkPS(int n){
        int sq = sqrt(n);
        if((sq*sq) == n)
            return true;
        
        return false;
    }
    int numSquares(int n) {
        if(checkPS(n))
            return 1;
        
        for(int i=1; i*i<=n; i++){
            if(checkPS(n - i*i))
                return 2;
        }

        int temp = n;
        while(temp % 4 == 0){
            temp /= 4;
        }
        if(temp % 8 == 7)
            return 4;

        return 3;
    }
};