class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &x: nums)
            mp[x]++;
        if(k == n)  return *max_element(nums.begin(), nums.end());

        if(k == 1)  {
            int maxi = INT_MIN;
            for(auto &x: mp)    {
                if(x.second == 1)   {
                    maxi = max(x.first, maxi);
                }
            }
            if(maxi != INT_MIN)     return maxi;
            else return -1;
        }

        if(mp[nums[0]] > 1)    {
            if(mp[nums[n-1]] > 1)
                return -1;
            else    return nums[n-1];
        }
        else {
            if(mp[nums[n-1]] > 1)
                return nums[0];
            else    return max(nums[0], nums[n-1]);
        }        
    }
};
