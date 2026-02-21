class Solution {
public:
    int findSumDigitSq(int num){
        int sum = 0;
        while(num > 0){
            int d = num%10;
            sum += d*d;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(fast != 1){
            slow = findSumDigitSq(slow);
            fast = findSumDigitSq(fast);
            fast = findSumDigitSq(fast);

            if(slow == fast && slow != 1)
                return false;
        }

        return true;
    }
};