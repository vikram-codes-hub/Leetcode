class Solution {
public:
    void inorder(TreeNode* root, int k, int &cnt, int &ans) {
        if (root == NULL) return;

        inorder(root->left, k, cnt, ans);

        cnt++;

        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k, cnt, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;

        inorder(root, k, cnt, ans);

        return ans;
    }
};