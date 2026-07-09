class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval); 
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merge;
        for (int i{0}; i < intervals.size(); ++i)
        {
            if (merge.empty() || intervals[i][0] > merge.back()[1])
            {
                merge.push_back({intervals[i]});
            }
            else
            {
                merge.back()[1] = max(merge.back()[1], intervals[i][1]);
            }
        }
        return merge;
    }
};