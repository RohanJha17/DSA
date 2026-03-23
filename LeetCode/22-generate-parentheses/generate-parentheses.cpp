class Solution {
public:
    void fun(int n, int open, int close, string& temp, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            fun(n, open+1, close, temp, ans);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            fun(n, open, close+1, temp, ans);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        fun(n, 0, 0, temp, ans);
        return ans;
    }
};