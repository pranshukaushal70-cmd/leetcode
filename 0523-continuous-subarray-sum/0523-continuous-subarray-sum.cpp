class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> prefixMod;
        prefixMod[0] = -1; 
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = sum % k;
            if(prefixMod.count(mod)){
                if(i - prefixMod[mod] >= 2) return true;
            } else {
                prefixMod[mod] = i; 
            }
        }
        return false;
    }
};