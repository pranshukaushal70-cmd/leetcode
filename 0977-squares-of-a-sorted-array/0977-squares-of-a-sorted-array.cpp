class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            arr.push_back(nums[i]*nums[i]);
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};