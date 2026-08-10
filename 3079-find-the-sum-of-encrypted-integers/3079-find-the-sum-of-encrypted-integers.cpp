class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            int maxDigit = 0;
            int temp = num;
            while (temp > 0) {
                maxDigit = max(maxDigit, temp % 10);
                temp /= 10;
            }
            int digitCount = to_string(num).length();
            int encrypted = 0;
            for (int i = 0; i < digitCount; i++) {
                encrypted = encrypted * 10 + maxDigit;
            }
            total += encrypted;
        }
        return total;
    }
};