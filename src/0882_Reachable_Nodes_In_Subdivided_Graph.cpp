#include <leetcode.hpp>

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> graph; // 2D hashmap
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        pq.push({maxMoves, 0});

        for (auto& edge: edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        } // fill graph

        while (!pq.empty()) {
            auto t= pq.top(); pq.pop(); // pop queue
            int move = t.first, cur = t.second;
            if (visited[cur]) continue;
            visited[cur] = true;
            ++ans;

            // Search neighbors(hashmap)
            for (auto &node: graph[cur]) {
                // node = {node_num, move}
                if (move > node.second && !visited[node.first]) {
                    pq.push({move - node.second - 1, node.first});
                }
                graph[node.first][cur] -= min(move, node.second);
                ans += min(move, node.second);
            }

        }


        return ans;
    }
};

/*
 * Main
 */


int main() {
    vector<vector<int>> edges{
        {0,1,4},{1,2,6},{0,2,7},{1,3,1}
    };
    Solution sol;

    cout << sol.reachableNodes(edges, 10, 4) << endl;

    return 0;
}
