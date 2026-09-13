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
    bool isSametree(TreeNode* root, TreeNode* root2) {
        if (root == nullptr && root2 == nullptr) return true;
        else if (root == nullptr || root2 == nullptr) return false;
        if (root->val == root2->val) return isSametree(root->left, root2->left) && isSametree(root->right, root2->right);
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (root == nullptr) return false;
        if (root->val == subroot->val) if (isSametree(root, subroot)) return true;
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};
