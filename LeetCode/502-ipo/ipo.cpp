class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int ,int>> projects;
        for(int i=0; i<profits.size(); i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int idx = 0;
        while(k--){
            while(idx < projects.size()){
                if(projects[idx].first > w)
                    break;

                pq.push(projects[idx].second);
                idx++;
            }

            if(pq.empty())
                return w;
            
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};