class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        for(char ch : text)
            have[ch]++;

        unordered_map<char, int> need = {
            {'b',1}, {'a',1}, {'l',2}, {'o',2}, {'n',1}
        };

        int count = INT_MAX;
        for(auto it : need){
            int times = have[it.first]/it.second;
            count = min(count, times);
        }

        return count;
    }
};