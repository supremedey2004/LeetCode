/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdbool.h>

bool validate(struct TreeNode* root, long min, long max) {
    
    if (root == NULL)
        return true;

    // current node must lie between min and max
    if (root->val <= min || root->val >= max)
        return false;

    // check left and right subtree
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    
    return validate(root, LONG_MIN, LONG_MAX);
}