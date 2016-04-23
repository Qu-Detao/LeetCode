/*
Given a positive integer n, find the least number of perfect 
square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) {
        if(isSquare(n))
            return 1;

        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while((n & 3) == 0) // n % 4 == 0  
            n >>= 2;
        if((n & 7) == 7)    // n % 8 == 7
            return 4;
        
        int sqrt_n = (int)sqrt(n);
        for(int i = 1; i <= sqrt_n; ++i){
            if(isSquare(n - i * i))
                return 2;
        }
        return 3;
    }
    
private:
    bool isSquare(int n){
        int sqrt_n = (int)sqrt(n);
        return (sqrt_n * sqrt_n == n);
    }
};

/*
class Solution {
public:
    int numSquares(int n) {
        if(n < 0)
            return 0;
        static vector<int> cntPerfectSquares({0});
        while(cntPerfectSquares.size() <= n){
            int m = cntPerfectSquares.size();
            int cnt = INT_MAX;
            for(int i = 1; i * i <= m; ++i)
                cnt = min(cnt, cntPerfectSquares[m - i * i] + 1);
            cntPerfectSquares.push_back(cnt);
        }
        return cntPerfectSquares[n];
    }
};
*/
