class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if(n == 0) return result;
        int start = nums[0];   
        for(int i = 1; i <= n; i++) {
            if(i == n || nums[i] != nums[i-1] + 1) {
                int end = nums[i-1];
                
                if(start == end) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
                if(i < n)
                    start = nums[i];  
            }
        }
        return result;
    }
};
