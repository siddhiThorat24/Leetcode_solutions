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
    int i = 0;

    TreeNode* build(vector<int>& preorder, long long bound) {

        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        int value = preorder[i++];

        TreeNode* root = new TreeNode(value);

        root->left = build(preorder, value);
        root->right = build(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        i = 0;

        return build(preorder, LLONG_MAX);
    }
};
