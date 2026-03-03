class Solution {
public:
    int lowerbound(vector<int>& arr, int n, int x){
    int low=0; int high=n-1;
    int ans=n;
    while(low <= high){
        int mid= (low+high)/2;
    if(arr[mid] >= x){
    ans=mid;
     high = mid-1;
    }
    else{
        low = mid+1;
    }
    }
    return ans;
}
    int upperbound(vector<int>& arr, int n, int x){
    int low=0; int high=n-1;
    int ans=n;
    while(low <= high){
        int mid= (low+high)/2;
    if(arr[mid] > x){
    ans=mid;
     high = mid-1;
    }
    else{
        low = mid+1;
    }
    }
    return ans;
}
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int negcnt=lowerbound(nums, n, 0);
        int poscnt=n-upperbound(nums, n, 0);
        int result=max(negcnt, poscnt);
        return result;
    }
};