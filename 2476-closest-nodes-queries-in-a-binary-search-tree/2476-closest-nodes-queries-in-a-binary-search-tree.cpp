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
    vector<int> nums;

    void inorder(TreeNode* root) {

        if (!root) return;

        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    vector<vector<int>> closestNodes(
        TreeNode* root, vector<int>& queries) {

        nums.clear();
        inorder(root);

        vector<vector<int>> ans;

        for (int q : queries) {

            auto it = lower_bound(nums.begin(), nums.end(), q);

            int mini = -1, maxi = -1;

            if (it != nums.end())
                maxi = *it;

            if (it != nums.end() && *it == q)
                mini = q;
            else if (it != nums.begin())
                mini = *prev(it);

            ans.push_back({mini, maxi});
        }

        return ans;
    }
};
