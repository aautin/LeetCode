/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode	t_tree;
int newNb(t_tree *node, int nb) {
	if (!node->left && !node->right)
		return (nb + node->val);
	int res = 0;
	if (node->left)
		res += newNb(node->left, (nb + node->val) * 10);
	if (node->right)
		res += newNb(node->right, (nb + node->val) * 10);
	return (res);
}
int sumNumbers(struct TreeNode* root) {
    return (newNb(root, 0));
}