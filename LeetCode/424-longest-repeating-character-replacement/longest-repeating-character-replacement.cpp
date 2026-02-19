class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(256, 0);
        int low = 0, maxLen = INT_MIN;
        for(int high=0; high<s.length(); high++){
            freq[s[high]]++;

            int len = high-low+1;
            int maxCount = *max_element(freq.begin(), freq.end());
            int diff = len - maxCount;

            while(diff > k){
                freq[s[low]]--;
                low++;

                len = high-low+1;
                maxCount = *max_element(freq.begin(), freq.end());
                diff = len - maxCount;
            }

            len = high-low+1;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};