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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //case1. dono null
        if(p == NULL && q == NULL) return true;

        //case2. ek null h
        if(p == NULL ||  q == NULL) return false;

        //case3. value diff. h
        if(p->val != q->val) return false;

        //case4. left & right subtree check
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
