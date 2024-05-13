/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Tree;
void    goLeaf(Tree *previous, Tree *current, int target, bool right) {
    if (current->left)
        goLeaf(current, current->left, target, false);
    if (current->right)
        goLeaf(current, current->right, target, true);
    if (current->val == target && !current->left && !current->right)
    {
        if (previous && right)
            previous->right = NULL;
        else if (previous)
            previous->left = NULL;
    }
}
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    goLeaf(NULL, root, target, 0);
    if (root->val == target && !root->left && !root->right)
        return NULL;
    return root;
}