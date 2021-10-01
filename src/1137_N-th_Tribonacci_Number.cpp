#include <leetcode.hpp>
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int t1 = 0, t2 = 1, t3 = 1;
        for (; n>2; --n) {
            int sum = t1+t2+t3;
            t1 = t2;
            t2 = t3;
            t3 = sum;
        }
        return t3;

    }
};

int main() {
    Solution sol;
    cout << sol.tribonacci(9) << endl;
    return 0;
}
