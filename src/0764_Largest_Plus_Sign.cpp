#include <leetcode.hpp>

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if (n==1) {
            // Just for simplest case
            if (mines.empty()) return 1;
            else return 0;
        }

        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto& mine:mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        // From left
        for (int i=0; i<n; i++) {
            int last = 1;
            for (int j=0; j<n; j++) {
                if (grid[i][j]!=0) {
                    grid[i][j] = last;
                    last++;
                } else {
                    last = 1;
                }
            }
        }

        // From right
        for (int i=0; i<n; i++) {
            int last = 1;
            for (int j=n-1; j>=0; j--) {
                if (grid[i][j]!=0) {
                    if (last < grid[i][j]) {
                        grid[i][j] = last;
                    }
                    last++;
                } else {
                    last = 1;
                }
            }
        }

        // From Top
        for (int i=0; i<n; i++) {
            int last = 1;
            for (int j=0; j<n; j++) {
                if (grid[j][i]!=0) {
                    if (last < grid[j][i]) {
                        grid[j][i] = last;
                    }
                    last++;

                } else {
                    last = 1;
                }
            }
        }

        // From down
        for (int i=0; i<n; i++) {
            int last = 1;
            for (int j=n-1; j>=0; j--) {
                if (grid[j][i]!=0) {
                    if (last < grid[j][i]) {
                        grid[j][i] = last;
                    }
                    last++;
                } else {
                    last = 1;
                }
            }
        }

        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans = ans > grid[i][j] ? ans : grid[i][j];

            }
        }



        /* for (int i=0; i<n; i++) { */
        /*     for (int j=0; j<n; j++) { */
        /*         cout << grid[i][j]; */
        /*     } */
        /*     cout << endl; */
        /* } */


        return ans;
    }
};

/*
 * Main
 */


int main() {
    vector<vector<int>> mines{
        {4,2}
    };
    Solution sol;

    cout << sol.orderOfLargestPlusSign(5, mines) << endl;

    return 0;
}
