#include<bits/stdc++.h>
bool possible(vector<int>& bloomDay, int day, int m, int k){
    int n=bloomDay.size();
    int count=0;
    int noofbqt=0;
    for(int i=0; i<n; i++){
        if(bloomDay[i] <= day){
            count++;
        }
        else{
            noofbqt += count/k;
            count=0;
        }
    }
    noofbqt += count/k;
    return noofbqt>=m;
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long required = 1LL * m * k;
        if(required > bloomDay.size()) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element( bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid=(low+high)/2;
            if(possible(bloomDay, mid, m, k)==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};