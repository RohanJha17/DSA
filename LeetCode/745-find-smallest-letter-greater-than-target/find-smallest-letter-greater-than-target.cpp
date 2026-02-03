class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, end = letters.size()-1;
        int pos = -1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(letters[mid] > target){
                pos = mid;
                end = mid-1;
            }
            else
                st = mid+1;
        }

        if(pos == -1)
            return letters[0];
        
        return letters[pos];
    }
};