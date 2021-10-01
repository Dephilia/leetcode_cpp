/*
 * Segment Tree
 *
 * Using vector to implement the tree
 * Node 0 for top
 * For a length of 10 array, [0] = 0~9, [1] = 0~4, [2] = 5~9, [3] = 0~2 ... etc.
 *
 * Using binary tree is fine, but I've tried that the memory cost and speed is worse than segment tree.
 */
#include <leetcode.hpp>

class NumArray {
private:
    vector<int> nums, segtree;

    void init(int idx, int left, int right){
        // idx: segtree sum index
        if (idx > segtree.size()-1) return;

        if (left == right) {
            segtree[idx] = nums[left];
            return;
        }
        int mid = ( left + right ) /2;

        init(idx*2+1, left, mid);
        init(idx*2+2, mid+1,  right);

        segtree[idx] = segtree[idx*2+1] + segtree[idx*2+2];
    }

    void up(int idx, int target_idx, int diff, int left, int right){
        // idx: segtree sum index
        if (idx > segtree.size()-1) return;
        if (target_idx < left || target_idx > right) return;

        if (left == right) {
            segtree[idx] += diff;
            return;
        }
        int mid = ( left + right ) /2;

        segtree[idx] += diff;
        up(idx*2+2, target_idx, diff, mid+1,  right);
        up(idx*2+1, target_idx, diff, left, mid);

    }

    int sumup(int idx, int l, int r, int left, int right){
        if ( idx > segtree.size()-1 ) return 0;
        if ( l <= left && r >= right ) return segtree[idx];
        if ( r < left || l > right) return 0;
        if ( r == l) return nums[r];

        int mid = ( left + right ) /2;
        int lval = sumup(idx*2+1, l, r, left, mid);
        int rval = sumup(idx*2+2, l, r, mid+1, right);
        return lval+rval;

    }

public:
    NumArray(vector<int>& nums){
        this->nums = nums;
        segtree.resize(nums.size()*4); // Node size should be at least (n * 2) * 2
        init(0, 0, nums.size()-1);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        up(0, index, diff, 0, nums.size()-1);
    }

    int sumRange(int left, int right) {
        return sumup(0, left, right, 0, nums.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/*
 * Main
 */

int main() {
    vector<int> nums{1,3,5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0,2) << endl;
    obj->update(1,2);
    cout << obj->sumRange(0,2) << endl;

    return 0;
}


