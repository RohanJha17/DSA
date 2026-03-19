class Solution {
public:
    int distance(vector<int> point){
        int x = point[0], y = point[1];
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k; i++){
            pq.push({distance(points[i]), i});
        }

        for(int i=k; i<points.size(); i++){
            int d = distance(points[i]);
            if(d < pq.top().first){
                pq.pop();
                pq.push({d, i});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};