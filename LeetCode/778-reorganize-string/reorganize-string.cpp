class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(char c : s){
            m[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto& it : m){
            pq.push({it.second, it.first});
        }

        string res = "";
        int seat = 0;
        while(!pq.empty()){
            pair<int, char> p1 = pq.top();
            pq.pop();

            if(seat == 0 || p1.second != res[seat-1]){
                res.push_back(p1.second);
                seat++;
                
                p1.first--;
                if(p1.first > 0)
                    pq.push(p1);
            }
            else{
                if(pq.empty())
                    return "";
                
                pair<int, char> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;

                p2.first--;
                if(p2.first > 0)
                    pq.push(p2);
                
                pq.push(p1);
            }
        }

        return res;
    }
};