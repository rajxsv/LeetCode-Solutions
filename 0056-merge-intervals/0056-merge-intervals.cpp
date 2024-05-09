class Solution {
public:

    static bool myCmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        stack<vector<int>> s;

        sort(intervals.begin(),intervals.end(),myCmp);

        s.push(intervals[0]);

        for(int i=1;i<n;i++){
            vector<int> top = s.top();

            if( (intervals[i][0] <= top[0] && intervals[i][1] >= top[0]) || 
                (intervals[i][0] <= top[1] && intervals[i][1] >= top[1]) || 
                (intervals[i][0] <= top[0] && intervals[i][1] >= top[1]) || 
                (intervals[i][0] >= top[0] && intervals[i][1] <= top[1])) {
                
                top[0] = min(intervals[i][0],top[0]);
                top[1] = max(intervals[i][1],top[1]);
                // cout << "am here with " << top[0] << " " << top[1] << endl;
                s.pop();
                s.push(top);
            } else {
                s.push(intervals[i]);
            }
        }
        intervals = {};
        while(!s.empty()){
            intervals.push_back(s.top());
            s.pop();
        }

        return intervals;

    }
};