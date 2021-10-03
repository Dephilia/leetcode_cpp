#include <leetcode.hpp>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rem = nums[0];

        for (auto& num:nums) {
            if (rem < 0) return false;
            if (num > rem) rem = num;
            rem--;
        }
        return true;
    }
};

int main() {
    vector<int> nums{2,3,1,1,4};

    Solution sol;
    cout << sol.canJump(nums) << endl;
    return 0;
}
