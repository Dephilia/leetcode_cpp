#include <leetcode.hpp>
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        int last1 = 0, last2 = 0;
        for (auto& num:nums) {
            int temp = last1;
            last1 = max(num + last2, last1);
            last2 = temp;

        }
        return max(last1, last2);
    }
};

int main() {
    Solution sol;
    vector<int> nums{2,7,9,3,1};

    cout << sol.rob(nums) << endl;
    return 0;
}
