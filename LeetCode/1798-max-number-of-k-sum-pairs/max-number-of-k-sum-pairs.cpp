class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size() == 0) 
            return 0;
        
        unordered_map<int, int>m;
        for(int val : nums){
            m[val]++;
        }
        
        int ops = 0;
        for(int x : nums){
            int req = k - x;
            if(m[x] > 0 && m[req] > 0){
                if(x == req && m[x] < 2)
                    continue;

                m[x]--;
                m[req]--;
                ops++;
            }
            
        }
        
        return ops;
    }
};