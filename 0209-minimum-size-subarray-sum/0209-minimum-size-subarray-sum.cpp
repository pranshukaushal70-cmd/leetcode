class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0; 
        int r=0; 
        int n=nums.size();
        int minlen=INT_MAX;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                int len=r-l+1;
                minlen=min(len, minlen);
                sum=sum-nums[l];
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};