class Solution {
public:
    int getSum(int a, int b) {
        int sum=0;
        if(a){
            sum+=a;
        }
        if(b) sum+=b;
        return sum;
    }
};