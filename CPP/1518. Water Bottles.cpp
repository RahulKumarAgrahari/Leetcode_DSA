
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int extra=0;
        while(numBottles >= numExchange) {
            extra = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += extra;
        }
        return ans;        
    }
};
