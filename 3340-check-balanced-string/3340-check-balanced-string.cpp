class Solution {
public:
    bool isBalanced(string num) {
        int sumeven=0;
        int sumodd=0;
        for(int i=0; i<num.size(); i++){
            if(i%2==0) sumeven+=num[i]-'0';
            if(i%2==1) sumodd+=num[i]-'0';
        }
        if(sumeven==sumodd) return true;
        return false;
    }
};