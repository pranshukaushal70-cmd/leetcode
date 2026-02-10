class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> map;
        int l=0;
        int r=0;
        int n=s.size();
        int m=t.size();
        int count=0;
        int minlen=INT_MAX;;
        int sindex=-1;
        for(int i=0; i<m; i++){
            map[t[i]]++;
        }
        while(r<n){
            if(map[s[r]]>0){
                count++;
            }
            map[s[r]]--;
            while(count == m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                map[s[l]]++;
                if(map[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};