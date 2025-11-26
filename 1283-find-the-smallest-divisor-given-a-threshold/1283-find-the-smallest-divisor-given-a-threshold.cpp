#include<bits/stdc++.h>
int findSum(vector<int>& nums, int divisor){
    long long total=0;
    int n=nums.size();
    for(int i=0; i<n; i++){
        total += ceil((double)(nums[i])/(divisor));
    }
    return total;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high= *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid=(low+high)/2;
            long long totalh=findSum(nums, mid);
            if(totalh <= threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};