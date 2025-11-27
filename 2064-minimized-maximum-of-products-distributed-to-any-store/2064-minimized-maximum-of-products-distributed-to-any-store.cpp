#include<bits/stdc++.h>
int findSum(vector<int>& quantities, int divisor){
    long long total=0;
    int n=quantities.size();
    for(int i=0; i<n; i++){
        total += ceil((double)(quantities[i])/(divisor));
    }
    return total;
}
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int k=quantities.size();
        int low=1;
        int high= *max_element(quantities.begin(), quantities.end());
        while(low <= high){
            int mid=(low+high)/2;
            long long totalh=findSum(quantities, mid);
            if(totalh <= n){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};