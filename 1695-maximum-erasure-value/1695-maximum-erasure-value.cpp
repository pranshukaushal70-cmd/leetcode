class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> hash(10001, -1);
        int l = 0;
        int sum = 0;
        int maxsum = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (hash[nums[r]] >= l) {
                while (l <= hash[nums[r]]) {
                    sum -= nums[l];
                    l++;
                }
            }
            sum += nums[r];
            maxsum = max(maxsum, sum);
            hash[nums[r]] = r;
        }
        return maxsum;
    }
};
