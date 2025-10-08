class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int l = a.size();
        int r = b.size();
        string ans = "";
        while(l>0 || r>0 || carry)  {
            int x = 0, y = 0;
            if(l>0)   {
                x = a[l-1] - '0';
                l--;
            }
            if(r>0)   {
                y = b[r-1] - '0';
                r--;
            }

            int digit = x ^ y ^ carry;
            if(digit)   ans += '1';
            else ans += '0';

            carry = (x&&y) || (x&&carry) || (y&&carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
