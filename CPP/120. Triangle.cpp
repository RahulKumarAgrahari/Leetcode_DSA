class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) 
    {        
        if(i == 0 && j == 0)    return  triangle[0][0];

        if(dp[i][j] != -1)      return dp[i][j];

        int rightUp = 1e9, leftUp = 1e9;
        
        if(j > 0)  
            leftUp = triangle[i][j] + rec(i-1, j-1, triangle, dp);
        if(j < i)    
            rightUp = triangle[i][j] + rec(i-1, j, triangle, dp);

        return dp[i][j] = min(leftUp, rightUp);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp;
        for(int i=0; i<m; i++) {
            vector<int> temp(triangle[i].size(), -1);
            dp.push_back(temp);
        }
        for(int i=0; i<m; i++)  {
            ans = min(ans, rec(m-1, i, triangle, dp));
        }
        return ans;
    }
};
