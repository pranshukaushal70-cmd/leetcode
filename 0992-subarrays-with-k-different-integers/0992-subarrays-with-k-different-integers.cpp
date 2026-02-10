class Solution {
public:
    int subarray(vector<int> &nums, int k){
        unordered_map<int, int> map;
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        while(r<n){
            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]] == 0){
                    map.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums, k) - subarray(nums, k-1);
    }
};