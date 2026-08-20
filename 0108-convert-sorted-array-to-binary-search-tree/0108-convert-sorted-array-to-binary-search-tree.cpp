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

TreeNode* helper(vector<int>&nums,int l,int h){
    if (l > h) {
    return NULL;
}
 int n=nums.size();
      
        int mid=l+(h-l)/2;

        TreeNode*newr=new TreeNode();
        newr->val=nums[mid];

        newr->left=helper(nums,l,mid-1);
        newr->right=helper(nums,mid+1,h);

        return newr;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
       return helper(nums,0,nums.size()-1);

    }
};