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
private:
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //Postorder Traversal: Left Right Root

        if (!root) {
            return {};
        }

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);

        return result;
    }
};