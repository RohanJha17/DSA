class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int low = 0, maxLen = INT_MIN;
        for(int high=0; high<s.length(); high++){
            m[s[high]]++;

            int k = high - low + 1;
            while(m.size() < k){
                m[s[low]]--;
                if(m[s[low]] == 0)
                    m.erase(s[low]);
                
                low++;
                k = high - low +1;
            }

            k = high - low + 1;
            maxLen = max(maxLen, k);
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};