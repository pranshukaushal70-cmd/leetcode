class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            long long product = 1;
            int x = i;
            while (x) {
                product *= (x % 10);
                x /= 10;
            }
            if (product % t == 0) return i;
        }
    }
};