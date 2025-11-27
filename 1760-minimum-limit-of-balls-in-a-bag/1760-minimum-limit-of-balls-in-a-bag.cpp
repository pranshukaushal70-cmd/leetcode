class Solution {
public:
    bool canMake(vector<int>& nums, int maxOperations, int x) {
     long long ops = 0;
    for (int i = 0; i < nums.size(); i++) {
    int balls = nums[i];
    if (balls > x) {
        ops += (balls - 1) / x;  
    }
    if (ops > maxOperations) return false;
}
return ops <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(nums, maxOperations, mid)) {
                ans = mid;        
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};