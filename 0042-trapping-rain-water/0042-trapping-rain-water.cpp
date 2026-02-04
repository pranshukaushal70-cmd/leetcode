class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0;
        int rightmax=0;
        int total=0;
        int l=0;
        int r= n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(leftmax > height[l]){
                    total += leftmax-height[l];
                }
                else{
                    leftmax = height[l];
                }
                l++;
            }
            if(height[l] > height[r]){
                if(rightmax > height[r]){
                    total += rightmax-height[r];
                }
                else{
                    rightmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};