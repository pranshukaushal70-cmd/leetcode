class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int n=nums.size();
        int zeros=0;
        int maxlength=0;
        int len;
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }
            if(zeros <= k){
                len=r-l+1;
                maxlength=max(len, maxlength);
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            r++;
        }
        return maxlength;
    }
};