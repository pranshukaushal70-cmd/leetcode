class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        long long current = 0;
        int parts = 1;
        for (int n : nums) {
            if (current + n > maxSum) {
                parts++;
                current = n;
                if (parts > k) return false;
            } else {
                current += n;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;
        for (int n : nums) high += n;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;   
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};
