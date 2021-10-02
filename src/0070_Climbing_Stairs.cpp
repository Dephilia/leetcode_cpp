#include <leetcode.hpp>
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        // cs(n) = cs(n-1) + cs(n-2)
        // [1, 2, 3, 5, 8....]
        int t1 = 1, t2 = 2;
        for (; n>2; --n) {
            int temp = t2;
            t2 = t1 + temp;
            t1 = temp;
        }
        return t2;
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairs(9) << endl;
    return 0;
}
