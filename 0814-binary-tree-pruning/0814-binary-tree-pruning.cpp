
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {

        if (root == nullptr)
            return nullptr;

        // Prune left subtree
        root->left = pruneTree(root->left);

        // Prune right subtree
        root->right = pruneTree(root->right);

        // Remove node if it is 0 and has no children
        if (root->val == 0 &&
            root->left == nullptr &&
            root->right == nullptr) {

            return nullptr;
        }

        return root;
    }
};
