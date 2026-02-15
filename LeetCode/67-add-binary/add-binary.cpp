class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int c = 0;
        string ans = "";

        while(i>= 0 || j >= 0  || c){
            int sum = c;

            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }

            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }

            ans += sum%2 + '0';
            c= sum/2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};