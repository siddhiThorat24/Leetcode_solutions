/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void findParent(TreeNode* root) {

        if (root == NULL)
            return;

        if (root->left) {
            parent[root->left] = root;
            findParent(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            findParent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target, int k) {

        parent.clear();
        findParent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            if (level == k) {
                vector<int> ans;

                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                TreeNode* neighbors[] = {
                    node->left,
                    node->right,
                    parent.count(node) ? parent[node] : NULL
                };

                for (TreeNode* next : neighbors) {

                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            level++;
        }

        return {};
    }
};
