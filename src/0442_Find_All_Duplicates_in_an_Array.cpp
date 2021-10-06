#include <leetcode.hpp>

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (auto& num: nums) {
            if (nums[abs(num) - 1] < 0) {
                ans.push_back(abs(num));
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums{4,3,2,7,8,2,3,1};
    cout << to_string(sol.findDuplicates(nums)) << endl;
    return 0;
}
