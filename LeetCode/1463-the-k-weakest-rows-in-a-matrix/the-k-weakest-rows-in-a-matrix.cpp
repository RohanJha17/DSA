class Solution {
public:
    int countOne(vector<int>& row){
        int count = 0;
        for(int i=0; i<row.size(); i++){
            if(row[i] == 1)
                count++;
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<mat.size(); i++){
            int soldiers = countOne(mat[i]);

            pq.push({soldiers, i});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};