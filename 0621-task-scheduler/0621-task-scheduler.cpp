class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks) {
            freq[task - 'A']++;
        }
        priority_queue<int> pq;
        for(int f : freq) {
            if(f > 0)
                pq.push(f);
        }
        int time = 0;
        while(!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            while(cycle > 0 && !pq.empty()) {
                int curr = pq.top();
                pq.pop();
                curr--;
                if(curr > 0)
                    temp.push_back(curr);
                time++;
                cycle--;
            }
            for(int x : temp) {
                pq.push(x);
            }
            if(!pq.empty()) {
                time += cycle;
            }
        }
        return time;
    }
};