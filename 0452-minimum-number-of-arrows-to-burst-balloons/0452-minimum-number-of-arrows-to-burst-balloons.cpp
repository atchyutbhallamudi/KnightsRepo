class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> merge;
        int breaks = 0;
        priority_queue<int,vector<int>,greater<int>> prevend;
        for(int i = 0;i<points.size();i++){
            if(merge.empty() || points[i][0] > merge.back()[1]){
                merge.push_back(points[i]);
                while(!prevend.empty())prevend.pop();
                prevend.push(points[i][1]);
            }
            else{
                if(points[i][0] > prevend.top()){
                    breaks++;
                    prevend.pop();
                }
                prevend.push(points[i][1]);
                merge.back()[1] = min(merge.back()[1], points[i][1]);
            }
        }
        cout << breaks << endl;
        return (int)merge.size() + breaks;
    }
};