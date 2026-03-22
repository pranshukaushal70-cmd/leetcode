class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto x:nums){
            mpp[x]++;
        }
        for(auto x:nums){
            if(x%2==0 && mpp[x]==1){
                return x;
            }
        }
        return -1;
    }
};