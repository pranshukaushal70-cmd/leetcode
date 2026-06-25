class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : hand){
            mp[x]++;
        }
        for(auto x : mp) pq.push(x.first);
        while(pq.size()){
            int val = pq.top();
            for(int i=0; i<groupSize; i++){
                if(mp.find(i+val) == mp.end()) return false;
                mp[i+val]--;
                if(mp[i+val] == 0){
                    pq.pop();
                }
            }
        }
        return true;
    }
};