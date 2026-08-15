class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool ltr = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> anss;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                anss.push_back(curr->val);

                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }

            if (!ltr) {
                reverse(anss.begin(), anss.end());
            }

            ans.push_back(anss);

            ltr = !ltr;
        }

        return ans;
    }
};