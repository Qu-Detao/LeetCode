/*
Implement pow(x, n).
*/

class Solution {
public:
    double myPow(double x, int n) {
        unsigned long long p;
        if(n < 0){
            x = 1 / x;
            p = -n;
        }else
            p = n;
        
        double result = 1;
        while(p){
            if(p & 1)
                result *= x;
            x *= x;
            p >>= 1;
        }
        
        return result;
    }
};
