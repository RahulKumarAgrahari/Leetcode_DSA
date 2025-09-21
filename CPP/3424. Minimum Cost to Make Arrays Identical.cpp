// For Quick and Easy Explanation Watch:  https://youtu.be/s9rbMMiNZIM

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long costAfterSort = 0, costBeforeSort = 0;

        for(int i=0; i<arr.size(); i++) 
            costBeforeSort += abs(arr[i] - brr[i]);        

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());        

        for(int i=0; i<arr.size(); i++) 
            costAfterSort += abs(arr[i] - brr[i]);

        return min(costAfterSort + k , costBeforeSort);
    }
};
