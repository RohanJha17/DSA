class Solution {
public:
    bool isPrime(int n){
        bool flag = true;
        for(int i=2; i*i<=n; i++){
            if(n % i == 0){
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool isPalindrome(int n){
        string s = to_string(n);

        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right])
                return false;

            left++; right--;
        }

        return true;
    }

    int primePalindrome(int n) {
        int num = (n==1) ? 2 : n;

        while(1){
            if((num > 1e3 and num < 1e4) or (num > 1e5 and num < 1e6) or (num > 1e7 and num < 1e8)){
                num = pow(10, ceil(log10(num)));
                continue;
            }

            if(isPrime(num) && isPalindrome(num))
                return num;
            num++;
        }

        return -1;    
    }
};