//Implement pow(x, n).
//
//Subscribe to see which companies asked this question.
//

class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        unsigned int exp = n;
        if( n<0 ) {
            exp = -n;
            sign = true;
        }

        double result = 1.0;
        while(exp) {
            if( exp&1 ) {
                result *= x;
            }
            exp >>= 1;
            x *= x;
        }
        return sign ? 1/result : result;
    }
};
