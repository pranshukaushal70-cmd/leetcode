#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxpiles(vector<int>& piles){
        int maxi = INT_MIN;
        for(int x : piles){
            maxi = max(x, maxi);
        }
        return maxi;
    }
    long long totalhours(vector<int>& piles, int hourly){
        long long total = 0;
        for(long long x : piles){
            total += (x + hourly - 1) / hourly;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;  
        int high = maxpiles(piles);
        while(low <= high){
            int mid = (low + high) / 2;
            long long hours = totalhours(piles, mid);
            if(hours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};