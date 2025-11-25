#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& piles){
    int maxi = INT_MIN;
    for(int x : piles){
        maxi = max(maxi, x);
    }
    return maxi;
}

long long findTotalhours(vector<int>& piles, int hourly){
    long long total = 0;
    for(long long x : piles){
        total += (x + hourly - 1) / hourly; 
    }
    return total;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalh = findTotalhours(piles, mid);

            if(totalh <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
