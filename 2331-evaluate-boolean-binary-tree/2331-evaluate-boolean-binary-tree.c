/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree;
bool evaluateTree(tree* root) {
    if (root->val < 2)
        return (root->val);
    if (root->val == 2)
        return (evaluateTree(root->left) || evaluateTree(root->right));
    return (evaluateTree(root->left) && evaluateTree(root->right));
}