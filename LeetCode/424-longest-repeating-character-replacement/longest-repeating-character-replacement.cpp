class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int low = 0, maxLen = 0, maxCount = 0;
        for(int high=0; high<s.length(); high++){
            freq[s[high] - 'A']++;

            maxCount = max(maxCount, freq[s[high]-'A']);
            int len = high-low+1;

            while(len - maxCount > k){
                freq[s[low]-'A']--;
                low++;

                len = high-low+1;
            }
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};