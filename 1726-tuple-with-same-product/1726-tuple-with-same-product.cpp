class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int total = 0;
        for (auto &it : mp) {
            int cnt = it.second;
            if (cnt > 1) {
                total += cnt * (cnt - 1) / 2 * 8;
            }
        }
        return total;
    }
};
