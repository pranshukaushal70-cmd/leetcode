class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int r=0;
        int l=0;
        int maxzeros=0;
        while(r<n){
            if(forts[r]){
                if(forts[l] == -forts[r]){
                    int zeros=r-l-1;
                    maxzeros=max(maxzeros, zeros);
                }
                l=r;
            }
            r++;
        }
        return maxzeros;
    }
};