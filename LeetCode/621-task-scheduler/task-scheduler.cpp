class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        unordered_map<char, int> free;
        for(char ch : tasks){
            m[ch]++;
            free[ch] = 1;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : m){
            pq.push({it.second, it.first});
        }

        int minInterval = 1;
        while(!pq.empty()){
            vector<pair<int, char>> hold;
            while(!pq.empty()){
                pair<int, char> p = pq.top();
                pq.pop();

                if(free[p.second] <= minInterval){
                    if(p.first > 1){
                        pq.push({p.first-1, p.second});
                        free[p.second] = minInterval + n + 1;
                    }
                    break;
                }
                else{
                    hold.push_back(p);
                }
            }
            for(int i=0; i<hold.size(); i++){
                pq.push(hold[i]);
            }
            minInterval++;
        }

        return minInterval - 1;
    }
};