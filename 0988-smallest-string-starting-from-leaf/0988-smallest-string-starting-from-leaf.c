/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Tree;
typedef struct stack {
    Tree            *leaf;
    struct stack    *next;
}   tStack;


char compare(Tree *leaf1, Tree *leaf2) {
    while (leaf1 && leaf2) {
        if (leaf1->val != leaf2->val)
            return leaf2->val - leaf1->val;
        leaf1 = leaf1->left;
        leaf2 = leaf2->left;
    }
    if (leaf1 && !leaf2)
        return -1;
    else
        return 1;
}
void    inverseTree(tStack **global, Tree *root, Tree *next) {
    Tree    *leftSave = NULL;
    Tree    *rightSave = NULL;
    if (!next->left && !next->right) {
        next->left = root;
        next->right = NULL;
        tStack  *newElement = malloc(sizeof(tStack));
        newElement->leaf = next;
        newElement->next = *global;
        *global = newElement;
    }
    else {
        if (next->left)
            leftSave = next->left;
        if (next->right)
            rightSave = next->right;
        next->left = root;
        next->right = NULL;

        if (leftSave)
            inverseTree(global, next, leftSave);
        if (rightSave)
            inverseTree(global, next, rightSave);
    }

}
char* smallestFromLeaf(Tree* root) {
    tStack *global = NULL;

    // inverse tree and store its leafs (becoming roots) in a stack
    if (!root->left && !root->right) {
        global = malloc(sizeof(tStack));
        global->leaf = root;
        global->next = NULL;
    }
    else {
        if (root->left)
            inverseTree(&global, root, root->left);
        if (root->right)
            inverseTree(&global, root, root->right);
        root->left = NULL;
        root->right = NULL;
    }
    
    // browse from the new roots and compare the value
    Tree  *solution = global->leaf;
	global = global->next;

	while (global) {
        if (compare(solution, global->leaf) < 0)
            solution = global->leaf;
        global = global->next;
    }

	// measure the len of the solution
    Tree    *save = solution;
    unsigned char i = 0;
    while (save) {
        save = save->left;
        i++;
    }

    // turn the solution (a root) into a string
    char    *str = malloc((i + 1) * sizeof(char));
    str[i] = '\0';
    i = 0;
    while (solution) {
        str[i++] = solution->val + 'a';
        solution = solution->left;
    }
    return str;
}
