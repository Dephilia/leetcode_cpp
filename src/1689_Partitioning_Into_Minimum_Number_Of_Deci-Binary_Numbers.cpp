#include <cstdio>
#include <leetcode.hpp>
class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        int tmp;
        for (auto& i:n){
            tmp = i-'0';
            ret = ret > tmp ? ret : tmp;
        }
        return ret;
    }
};

/*
 * Main
 */


int main() {

    Solution sol;

    printf("Input:  n=27346209830709182346\n");
    printf("Output: %d", sol.minPartitions("27346209830709182346"));

    return 0;
}
