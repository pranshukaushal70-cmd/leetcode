class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cl=0;
        int cr=0;
        int remain=0;
        for(char it : moves){
            if(it=='L') cl++;
            if(it=='R') cr++;
            if(it=='_') remain++;
        }
        if(cl>cr) return remain+cl-cr;
        return remain+cr-cl;
    }
};