class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(char ch : s)
            m[ch]++;

        bool odd = false;
        int maxLen = 0;
        for(auto it : m){
            int val = it.second;
            if(val % 2 == 0)
                maxLen += val;
            else
                odd = true;
        }
        if(odd == false)
            return maxLen;

        for(auto it : m){
            int val = it.second;
            if(val % 2 == 1)
                maxLen += val-1;
        }
        return maxLen+1;
    }
};