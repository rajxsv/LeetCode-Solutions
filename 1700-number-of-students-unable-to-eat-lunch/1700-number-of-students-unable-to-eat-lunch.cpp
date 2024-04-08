class Solution {
public:
    int countStudents(vector<int>& a, vector<int>& b) {
        queue<int> q;
        deque<int> dq;
        int n=b.size();
        int streak=0;
        for(int i=0;i<n;i++){
            q.push(b[i]);
            dq.push_back(a[i]);
        }
        while(!dq.empty()) {
            if(dq.front()==q.front()) {
                dq.pop_front();
                q.pop();
                streak=0;
            } else {
                dq.push_back(dq.front());
                dq.pop_front();
                streak++;
            }
            if(streak==n) break;
        }
        return dq.size();
    }
};