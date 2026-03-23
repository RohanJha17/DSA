class Solution {
public:
    void helper(string& s, int n, int idx, string& temp, vector<string>& ans, unordered_map<char, string>m){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        string choice = m[s[idx]];
        for(int j=0; j<choice.length(); j++){
            temp.push_back(choice[j]);
            helper(s, n, idx+1, temp, ans, m);
            temp.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans;
        string temp = "";

        helper(digits, digits.length(), 0, temp, ans, m);

        return ans;
    }
};