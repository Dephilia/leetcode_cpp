#include <leetcode.hpp>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s1 = 0, s2 = 0; // s1 is 1 step before, s2 is 2 step before
        for (auto& c: cost) {
            int temp = s1;
            s1 = c +  (s1 > s2 ? s2 : s1); // s1 = this cost + min(s1,s2)
            s2 = temp; // s2 = last s1
        }
        return s1 > s2 ? s2 : s1;
    }
};

int main() {
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};

    Solution sol;

    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
