#include <leetcode.hpp>
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int t1 = 0, t2 = 1;
        for (; n>1; --n) {
            int temp = t2;
            t2 = t1 + temp;
            t1 = temp;
        }
        return t2;
    }
};


int main() {
    Solution sol;
    cout << sol.fib(9) << endl;
    return 0;
}
