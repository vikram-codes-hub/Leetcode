class Solution {
public:
    bool solve(TreeNode* root, long long minvalue, long long maxvalue) {
        if(root == NULL)
            return true;

        if(root->val <= minvalue || root->val >= maxvalue)
            return false;

        return solve(root->left, minvalue, root->val) &&
               solve(root->right, root->val, maxvalue);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};