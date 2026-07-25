class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int maxarea=0;
        sort(points.begin(), points.end());
        for(int i=0; i<points.size()-1; i++){
            int diff=points[i+1][0]-points[i][0];
            maxarea=max(diff, maxarea);
        }
        return maxarea;
    }
};