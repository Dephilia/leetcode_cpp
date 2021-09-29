/**
 * LeetCode Common DataStruct.
 */
#include <stdc++.h>
#include <regex>
using namespace std;
using ll = long long;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};


static TreeNode *parse_tree(string s) {
    const regex re(",");
    vector<string> v(sregex_token_iterator(++s.begin(), --s.end(), re, -1), sregex_token_iterator());
    if (v.empty()) return nullptr;
    vector<TreeNode *> ns;
    ns.push_back(new TreeNode(stoi(v.front())));
    for (int i = 1; i < v.size(); ++i) {
        TreeNode *cur = v[i].find("null") != string::npos ? nullptr : new TreeNode(stoi(v[i]));
        if (i % 2 == 1) ns[(i - 1) / 2]->left = cur;
        else ns[(i - 1) / 2]->right = cur;
        if (cur) ns.push_back(cur);
    }
    return ns.front();
}

static string to_string(TreeNode *root) {
    if (!root) return "null";
    if (!root->left && !root->right) return to_string(root->val);
    return "{" + to_string(root->val) + ", " + to_string(root->left) + ", " + to_string(root->right) + "}";
}

static void print(TreeNode *head, int len = 4, int height = 0, string to = "#") {
    if (!head) return;
    print(head->right, len, height + 1, "v");
    string val = to + to_string(head->val);
    int lenM = val.length(), lenL = (len - lenM) / 2, lenR = len - lenM - lenL;
    val = string(height * len, ' ') + string(lenL, ' ') + val + string(lenR, ' ');
    cout << val << endl;
    print(head->left, len, height + 1, "^");
}

/// =========================================================================

struct ListNode {

    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static ListNode *parse_list(string s) {
    s.pop_back();
    s.erase(s.begin());
    const regex re(",");
    vector<string> v(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
    ListNode *mock = new ListNode(-1), *p = mock;
    for (auto &i : v) {
        p->next = new ListNode(stoi(i));
        p = p->next;
    }
    return mock->next;
}

static string _helper_to_string(ListNode *node) {
    if (!node) return "";
    return to_string(node->val) + (node->next ? "," + _helper_to_string(node->next) : "");
}

static string to_string(ListNode *node) {
    return "[" + _helper_to_string(node) + "]";
}

static void print(ListNode *node) {
    cout << to_string(node) << endl;
}

/// =========================================================================

struct Interval {

    int start, end;

    Interval() : start(0), end(0) {}

    Interval(int start, int anEnd) : start(start), end(anEnd) {}
};

/// =========================================================================
