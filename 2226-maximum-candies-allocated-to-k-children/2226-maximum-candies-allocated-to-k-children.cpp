bool check(vector<int>& candies, long long k, long long x){
    long long count=0;
    int n=candies.size();
    for(int i=0; i<n; i++){
        count += candies[i]/x;
    }
    if(count >= k) return true;
    else return false;
}
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
    long long low = 1;
    long long high = *max_element(candies.begin(), candies.end());
    long long ans =0;
    while(low <= high){
        long long mid=(low+high)/2;
        if(check(candies, k, mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
    }
};