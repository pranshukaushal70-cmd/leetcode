class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1 && nums[i] < nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
            if (i % 2 == 0 && nums[i] > nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};
