class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxcount=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count++;
                maxcount=max(count, maxcount);
            }
            if(s[i] == ')'){
                count--;
            }
        }
        return maxcount;
    }
};