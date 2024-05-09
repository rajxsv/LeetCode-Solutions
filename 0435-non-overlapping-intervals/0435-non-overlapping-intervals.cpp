class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int arrow = INT_MIN;

        for (const auto& interval : intervals) {
            if (interval[0] >= arrow) {
                arrow = interval[1];
            } else {
                count++;
                arrow = min(interval[1], arrow);
            }
        }

        return count;
    }
};
