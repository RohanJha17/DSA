class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        
        priority_queue<int>pq;

        int time = 0;
        for(auto& it : courses){
            int dur = it[0];
            int last = it[1];

            time += dur;
            pq.push(dur);

            if(time > last){
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};