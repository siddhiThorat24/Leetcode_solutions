/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> values;

    void inorder(TreeNode* root) {

        if (!root) return;

        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {

        if (l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(values[mid]);

        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        values.clear();
        inorder(root);

        return build(0, values.size() - 1);
    }
};
