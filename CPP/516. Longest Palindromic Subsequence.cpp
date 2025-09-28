class Solution {
private:
    int lcs(string& s, string& t)   {
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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};
