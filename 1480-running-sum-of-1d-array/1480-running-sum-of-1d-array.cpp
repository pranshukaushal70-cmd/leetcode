class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int x=0;
        for(int i=0; i<nums.size(); i++){
            x+=nums[i];
            sum.push_back(x);
        }
        return sum;
    }
};