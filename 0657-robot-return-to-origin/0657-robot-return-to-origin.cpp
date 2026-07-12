class Solution {
public:
    bool judgeCircle(string moves) {
        int cud=0;
        int crl=0;
        for(char it : moves){
            if(it=='U') cud++;
            if(it=='D') cud--;
            if(it=='R') crl++;
            if(it=='L') crl--;
        }
        if(cud==0 && crl==0) return true;
        return false;
    }
};