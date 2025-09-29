class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int longest = 0;

        for(int i=0; i<s.size(); ++i)   {
            // For Odd length palindrome
            int l = i, r = i;
            while(l>=0 && r<s.size() && s[l] == s[r])   {
                int len = r-l+1;
                if(len > longest) {
                    longest = len;
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }
            // For Even length palindrome
            l = i;
            r = i+1;
            while(l>=0 && r<s.size() && s[l] == s[r])   {
                int len = r-l+1;
                if(len > longest) {
                    longest = len;
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};
