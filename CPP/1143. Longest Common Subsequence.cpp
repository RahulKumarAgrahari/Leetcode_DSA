class Solution {
private:
    // Recursive soln:
    int rec(int idx1, int idx2, string& s, string& t)   {
        if(s[idx1] == t[idx2])  
            return 1 + rec(idx1-1, idx2-1, s, t);
        
        return max(rec(idx1, idx2-1, s, t), rec(idx1-1, idx2, s, t));
    }

    // Memoization:
    int memo(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp) {
        if(idx1 < 0 || idx2 < 0)    return 0;

        if(dp[idx1][idx2] != -1)    return dp[idx1][idx2];

        if(s[idx1] == t[idx2])  return dp[idx1][idx2] == 1 + memo(idx1-1, idx2-1, s, t, dp);

        return dp[idx1][idx2] = max(memo(idx1, idx2-1, s, t, dp), memo(idx1-1, idx2, s, t, dp));
    }

    // Tabulation:
    int tab(string& s, string& t)       {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // shifting the indices by +1 to resolve the -1 indices denoting empty strings

        for(int i=0; i<=n1; ++i)
            dp[i][0] = 0;
        for(int i=0; i<=n2; ++i)        
            dp[0][i] = 0;
        for(int i=1; i<=n1; ++i) {
            for(int j=1; j<=n2; ++j)  {
                if(s[i-1] == t[j-1])            // Here, s[i-1] & t[j-1] to compensate shifting
                    dp[i][j] = 1 + dp[i-1][j-1];
                else                
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n1][n2];
    }

    // Optimal Soln: Space-Optimized tabulation
    int optimal(string& s, string& t)   {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        vector<int> prev(n2+1, 0), cur(n2+1, 0);
        // shifting the indices by +1 to resolve the -1 indices denoting empty strings

        for(int i=0; i<=n1; ++i)
            dp[i][0] = 0;
        for(int i=0; i<=n2; ++i)        
            dp[0][i] = 0;

        for(int i=1; i<=n1; ++i) {            
            for(int j=1; j<=n2; ++j)  {
                if(s[i-1] == t[j-1])            // Here, s[i-1] & t[j-1] to compensate shifting
                    cur[j] = 1 + prev[j-1];
                else                
                    cur[j] = max(cur[j-1], prev[j]);
            }
            prev = cur;
        }
        return prev[n2];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // return tab(text1, text2);
        return optimal(text1, text2);
    }
};
