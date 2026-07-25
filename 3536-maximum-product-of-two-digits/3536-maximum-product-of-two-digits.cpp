class Solution {
public:
    int maxProduct(int n) {
        int mul = 1;
        priority_queue<int> pq;
        while (n > 0) {
            pq.push(n%10);
            n=n/10;
        }
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        return a*b;
    }
};