class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;
        while (start <= n) {
            long long end = min(start * 1000 - 1, (long long)n);
            long long count = end - start + 1;
            ans += count * commas;
            start *= 1000;
            commas++;
        }
        return ans;
    }
};