#include <leetcode.hpp>
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
class Solution {
public:
    int res = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node;

        if (l1 == nullptr && l2 == nullptr) {
            if (res) {
                node = new ListNode(res);
                return node;
            }
            return nullptr;
        }


        int tot;
        if (l1 == nullptr ) {
            tot = l2->val;
        } else if (l2 == nullptr ) {
            tot = l1->val;
        } else {
            tot = l1->val+l2->val;
        }

        tot += res;
        res = tot/10;

        if (l1 == nullptr ) {
            node = new ListNode(tot%10, addTwoNumbers(nullptr, l2->next));
        } else if (l2 == nullptr ) {
            node = new ListNode(tot%10, addTwoNumbers(l1->next, nullptr));
        } else {
            node = new ListNode(tot%10, addTwoNumbers(l1->next, l2->next));
        }

        return node;
    }
};

/*
 * Main
 */


int main() {
    ListNode* l1 = parse_list("[9,9,9,9,9,9,9]");
    ListNode* l2 = parse_list("[9,9,9,9]");

    Solution sol;

    cout << to_string(sol.addTwoNumbers(l1,l2)) << endl;

    return 0;
}
