class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<int> arr;
        for(int x : nums){
            if(arr.empty() || arr.back() != x){
            arr.push_back(x);
            }
        }
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) cnt++;
            if(arr[i]<arr[i+1] && arr[i]<arr[i-1]) cnt++;
        }
        return cnt;
    }
};