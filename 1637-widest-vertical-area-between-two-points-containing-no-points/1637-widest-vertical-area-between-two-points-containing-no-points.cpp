class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> arr;
        int maxarea=0;
        for(auto& it : points){
            int a=it[0];
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()-1; i++){
            int diff=arr[i+1]-arr[i];
            maxarea=max(diff, maxarea);
        }
        return maxarea;
    }
};