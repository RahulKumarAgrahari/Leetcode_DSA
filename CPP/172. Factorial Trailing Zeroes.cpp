class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;

        while(n>0)  {
            n /= 5;
            sum += n;
        }
        return sum;
    }

    /* ======================= EXPLANATION ==========================

    Trailing 0's means how many times completely divisible by 10
    And 10 = 2*5, for making a 10, atlest one 2 and one 5 are req.
    But 2's are much more in any the factorial than 5, coz every other no. is even, so no. of 5's will decide the no. of trailing 0's
    Now, We need the no. of 5's in the entire factorial

    n! = 1*2*3*4*5*......*25*.......*125*..........*625*.............*n

    Upon observation, Every 5th no. is a multiple of 5,
    So, no. of 0's = floor(n/5)
    But also, every 25th no. is a multiple of 5*5, one of which we have counted but not the other
    So, no. of 0's = floor(n/5) + floor(n/25)
    Similarly for every 125th no., multiple of 5*5*5, and so on....

    THUS,
    No. of 0's = floor(n/5) + floor(n/25) + floor(n/125) + floor(n/625) + .....
    ==================================================================
    */
};
