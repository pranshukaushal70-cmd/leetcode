class Solution {
public:

    long long totalcars(vector<int>& ranks, long long time){
        long long car = 0;
        for(int r : ranks){
            car += sqrt(time / r);
        }
        return car;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long)*max_element(ranks.begin(), ranks.end()) * cars * cars;
        while(low <= high){
            long long mid = (low + high) / 2;
            long long car = totalcars(ranks, mid);
            if(car >= cars)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};