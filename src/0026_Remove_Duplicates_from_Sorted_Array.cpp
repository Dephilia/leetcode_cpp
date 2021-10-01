#include <leetcode.hpp>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.empty() ) return 0;
        int index = 1;
        int last = nums[0];
        for (auto& num:nums) {
            if ( num != last ) {
                nums[index] = num;
                index++;
            }
            last = num;
        }
        return index;
    }
};

/*
 * Main
 */

int main() {
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution sol;

    cout << sol.removeDuplicates(nums) << endl;
    cout << to_string(nums) << endl;
    return 0;
}
