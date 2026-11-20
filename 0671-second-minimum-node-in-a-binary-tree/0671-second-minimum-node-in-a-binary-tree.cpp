class Solution {
public:
    long long ans = LLONG_MAX;

    void dfs(TreeNode* root, int minimum) {
        if (root == NULL)
            return;

        if (root->val > minimum) {
            ans = min(ans, (long long)root->val);
            return;
        }

        dfs(root->left, minimum);
        dfs(root->right, minimum);
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
