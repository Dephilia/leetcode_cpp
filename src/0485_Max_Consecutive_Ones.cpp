#include <leetcode.hpp>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 0;
        int temp = 0;
        for (auto& num: nums) {
            if (num == 1) temp++;
            else temp = 0;

            if (temp > ans) ans = temp;
        }
        return ans;
    }
};


/*
 * Main
 */


int main() {
    vector<int> nums{1,0,1,1,0,1};
    Solution sol;

    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}


