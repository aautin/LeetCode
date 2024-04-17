/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode t_tree;

void    goBranch(t_tree *node, short val, short depth) {
    
    if (depth == 2) {
        t_tree  *newNode;

        newNode = malloc(sizeof(t_tree));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = node->right;
        node->right = newNode;

        newNode = malloc(sizeof(t_tree));
        newNode->val = val;
        newNode->right = NULL;
        newNode->left = node->left;
        node->left = newNode;
    }
    else {
        if (node->left)
            goBranch(node->left, val, depth - 1);
        if (node->right)
            goBranch(node->right, val, depth - 1);
    }
}
struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    if (depth == 1) {
        t_tree  *newNode = malloc(sizeof(t_tree));
        newNode->val = val;
        newNode->left = root;
        newNode->right = NULL;
        return newNode;
    }
    goBranch(root, val, depth);
    return root;
}