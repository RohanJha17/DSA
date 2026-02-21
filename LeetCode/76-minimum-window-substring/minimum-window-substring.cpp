class Solution {
public:
    bool isValid(vector<int>& freqS, vector<int>& freqT){
        for(int i=0; i<256; i++){
            if(freqS[i] < freqT[i])
                return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";

        vector<int>freqT(256,0), freqS(256,0);
        for(int i=0; i<t.length(); i++){
            freqT[t[i]]++;
        }

        int low = 0, minLen = INT_MAX, start = -1;
        for(int high=0; high<s.length(); high++){
            freqS[s[high]]++;

            while(isValid(freqS, freqT)){
                int len = high-low+1;
                if(minLen > len){
                    minLen = len;
                    start = low;
                }

                freqS[s[low]]--;
                low++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};