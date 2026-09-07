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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> bfs;
        bfs.push(root);

        vector<vector<int>> result;
        vector<int> temp;
        int flag = (root == nullptr) ? 0 : 1;
        int nodes = 0;
        while (!bfs.empty()) {
            TreeNode* element = bfs.front();
            bfs.pop();
            
            temp.push_back(element->val);
            flag--;

            if (element->left != nullptr) {
                bfs.push(element->left);
                nodes++;
            }
            if (element->right != nullptr) {
                bfs.push(element->right);
                nodes++;
            }

            if (flag == 0) {
                result.push_back(temp);
                temp.clear();
                flag = nodes;
                nodes = 0;
            }
        }
        return result;
    }
};
