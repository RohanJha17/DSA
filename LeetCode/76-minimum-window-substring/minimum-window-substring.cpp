class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";

        vector<int>freq(256,0);
        for(char ch : t){
            freq[ch]++;
        }

        int low = 0, minLen = INT_MAX, start = -1, count = 0;
        for(int high=0; high<s.length(); high++){
            if(freq[s[high]] > 0)
                count++;
            freq[s[high]]--;

            while(count == t.length()){
                int len = high-low+1;
                if(minLen > len){
                    minLen = len;
                    start = low;
                }

                freq[s[low]]++;
                if(freq[s[low]] > 0)
                    count--;
                low++;
            }
        }

        if(start == -1)
            return "";

        return s.substr(start, minLen);
    }
};