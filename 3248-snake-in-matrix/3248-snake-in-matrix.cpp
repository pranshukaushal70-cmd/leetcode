class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int k=0;
        int j=0;
        for(int i=0; i<commands.size(); i++){
            if(commands[i][0]=='R'){
                j++;
            }
            if(commands[i][0]=='L'){
                j--;
            }
            if(commands[i][0]=='U'){
                k--;
            }
            if(commands[i][0]=='D'){
                k++;
            }
        }
        return (k*n)+j;
    }
};