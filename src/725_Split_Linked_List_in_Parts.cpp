/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <leetcode.hpp>
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = 0;
        ListNode* cur = head;

        // Count
        while (cur != nullptr){
            n++;
            cur = cur->next;
        }

        // Situation k >= n
        if ( k >= n) {
            cur = head;
            ListNode* node;
            while (cur != nullptr){
                node = new ListNode(cur->val);
                ans.push_back(node);
                cur = cur->next;
            }
            for (int i=0; i<k-n; ++i) ans.push_back(nullptr);
            return ans;
        }

        // Situation k < n
        cur = head;
        int m = n/k;
        int r = n%k;
        int count = m + (r > 0);
        r--;

        ans.push_back(cur);
        while (cur != nullptr){
            count--;
            if (count==0) {
                ListNode* temp = cur;
                cur = cur->next;
                if (cur != nullptr) ans.push_back(cur);
                temp->next = nullptr;
                count = m + (r > 0);
                r--;
            } else {
              cur = cur->next;  
            }

        }
        return ans;
    }
};

/*
 * Main
 */


int main() {
    ListNode* head = parse_list("[1,2,3,4,5,6,7,8,9,10]");

    Solution sol;

    cout << to_string(sol.splitListToParts(head, 3)) << endl;

    return 0;
}
