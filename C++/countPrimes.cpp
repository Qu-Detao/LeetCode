/*
Description:
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n){
        bool* isPrime = new bool[n];
        for(int i = 3; i < n; i += 2)
            isPrime[i] = true;
        
        for(int i = 3; i * i < n; i += 2){
            if(!isPrime[i]) continue;
            for(int j = i * i; j < n; j += i + i)
                isPrime[j] = false;
        }
        
        int count = 0;
        if(n > 2) count++;
        for(int i = 3; i < n; i += 2)
            if (isPrime[i]) count++;
        
        delete[] isPrime;
        return count;
    }
};
