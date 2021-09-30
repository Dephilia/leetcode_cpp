#include <leetcode.hpp>
class Solution {
public:
    double myPow(double x, int n) {
        if ( x==0 ) return 0;
        double res = 1.0, cur;
        unsigned int pow;
        if (n==1) {
            return x;
        } else if (n==0) {
            return 1;
        } else if (n==-1) {
            return 1/x;
        } else if (n<0) {
            cur = 1/x;
            pow = (unsigned int)(-(n + 1)) + 1; // Important, prevent overflow
        } else {
            cur = x;
            pow = n; 
        }
        for (;pow > 0; pow >>= 1) {  
            if (pow & 1) res *= cur;
            cur *= cur;
        }
        return res;
    }
};


/*
 * Main
 */


int main() {

    Solution sol;

    cout << sol.myPow(1.23456, -7) << endl;

    return 0;
}
