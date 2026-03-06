class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        for(char ch : magazine){
            have[ch]++;
        }

        unordered_map<char, int> need;
        for(char c : ransomNote)
            need[c]++;

        for(auto it : need){
            if(have[it.first] < it.second)
                return false;
        }

        return true;
    }
};