class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;

        int low = 0;
        int maxFruits = -1;
        for(int high=0; high<fruits.size(); high++){
            m[fruits[high]]++;

            while(m.size() > 2){
                m[fruits[low]]--;
                if(m[fruits[low]] == 0)
                    m.erase(fruits[low]);
                
                low++;
            }

            int len = high-low+1;
            maxFruits = max(maxFruits, len);
        }

        return maxFruits;
    }
};