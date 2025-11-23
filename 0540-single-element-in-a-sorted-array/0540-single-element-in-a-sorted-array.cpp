class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid]^nums[mid+1] != 0 || nums[mid-1]^nums[mid] != 0){
                return mid;
            }
            if(nums[mid] == nums[mid+1]){
                low=mid+1;
            }
            else if(nums[mid-1] == nums[mid]){
                high=mid-1;
            }
        }
        return -1;
    }
};