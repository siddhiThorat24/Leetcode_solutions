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
    int index = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int start, int end) {

        if (start > end)
            return NULL;

        int value = preorder[index++];
        TreeNode* root = new TreeNode(value);

        int pos = start;

        while (inorder[pos] != value)
            pos++;

        root->left = build(preorder, inorder, start, pos - 1);

        root->right = build(preorder, inorder, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        index = 0;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
