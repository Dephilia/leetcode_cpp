/*
 *
 */
#include <leetcode.hpp>


class Solution {
public:
    using ll = long long; // Unsigned int64

    int rectangleArea(vector<vector<int>>& rectangles) {
        ll result = 0;

        

        return result % (ll)(1e9+7);

    }
};

/*
 * Main
 */

template <class T>
void assert_eq(T _a, T _b){
    if (_a == _b) {
        cout << "Pass! Value: (" << _a << ", " << _b << ")" << endl;
    } else {
        cout << "Fail! Value: (" << _a << ", " << _b << ")" << endl;
    }
}

int main() {
    vector<vector<int>> rectangle1{
        {0,0,2,2},
        {1,0,2,3},
        {1,0,3,1}
    };
    vector<vector<int>> rectangle2{
        {0,0,1000000000,1000000000}
    };

    Solution sol;

    assert_eq(sol.rectangleArea(rectangle1), 6);
    assert_eq(sol.rectangleArea(rectangle2), 49);
    return 0;
}
