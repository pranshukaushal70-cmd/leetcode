class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int rightmax=0;
        int leftmax=0;
        int totalunit=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l]<=leftmax){
                    totalunit+=leftmax-height[l];
                }
                else{
                    leftmax=height[l];
                }
                l++;
            }
            else{
                if(height[r]<=rightmax){
                    totalunit+=rightmax-height[r];
                }
                else{
                    rightmax=height[r];
                }
                r--;
            }

        }
        return totalunit;
    }
};